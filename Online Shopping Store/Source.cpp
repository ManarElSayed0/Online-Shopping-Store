#include <iostream>
#include<string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct Shopper
{
    string name;
    string id;
    string password;
    string age;
    int Cart_counter;
    string cart[10];
    float Receipt;
    string gender;
    string address;
};
struct Shop_Owner
{
    string name;
    string id;
    string password;
    string age;
    string gender;
    string address;
    string shop_name;
    string address_shop;
    string category_shop;
};
struct Product
{
    string Product_code;
    string product_name;
    double price;
    string Shop_Owner_ID;
    string category;
    int quantity;
};

void Save();

int Products_cap, Shoper_cap, Owners_cap, Products_counter, Shopers_counter, Owners_counter;
Shop_Owner* Owners;
Shopper* Shopers;
Product* products;
void initializefunc() {
    Products_cap = 5;
    Shoper_cap = 5;
    Owners_cap = 5;
    Products_counter = 0;
    Shopers_counter = 0;
    Owners_counter = 0;
    Owners = new Shop_Owner[Owners_cap];
    Shopers = new Shopper[Shoper_cap];
    products = new Product[Products_cap];
}
int index;
void expand_products() {
    if (Products_cap == Products_counter) {
        Product* newarr = new Product[Products_cap + 5];
        for (int i = 0; i < Products_cap; i++)
        {
            newarr[i] = products[i];
        }
        delete[] products;
        products = newarr;
        Products_cap += 5;
    }
}
void expand_shopers() {
    if (Shoper_cap == Shopers_counter) {
        Shopper* newarr = new Shopper[Shoper_cap + 5];
        for (int i = 0; i < Shoper_cap; i++) {
            newarr[i] = Shopers[i];
        }
        delete[] Shopers;
        Shopers = newarr;
        Shoper_cap += 5;
    }
}
void expand_owners() {
    if (Owners_cap == Owners_counter) {
        Shop_Owner* newarr = new Shop_Owner[Owners_cap + 5];
        for (int i = 0; i < Owners_cap; i++)
        {
            newarr[i] = Owners[i];
        }
        delete[] Owners;
        Owners = newarr;
        Owners_cap += 5;
    }
}
void Edit_Owner()
{
    cout << "Name : ";
    cin >> Owners[index].name;
    cout << "Password : ";
    cin >> Owners[index].password;
    cout << "Gender : ";
    cin >> Owners[index].gender;
    cout << "Address : ";
    cin >> Owners[index].address;
    cout << "Shop Name : ";
    cin >> Owners[index].shop_name;
    cout << "Shop Address : ";
    cin >> Owners[index].address_shop;
    cout << "Shop Category :";
    cin >> Owners[index].category_shop;
    cout << "Age : ";
    cin >> Owners[index].age;
    Save();
}

void Save() {
    ofstream Shopers_file("Shopers.txt");
    Shopers_file.trunc;
    ofstream Carts_file("Carts.txt");
    Carts_file.trunc;
    if (Shopers_file.is_open()) {
        for (int i = 0; i < Shopers_counter; i++)
        {
            Shopers_file << Shopers[i].id << "\n";
            Shopers_file << Shopers[i].name << "\n";
            Shopers_file << Shopers[i].age << "\n";
            Shopers_file << Shopers[i].address << "\n";
            Shopers_file << Shopers[i].gender << "\n";
            Shopers_file << Shopers[i].password << "\n";
            Shopers_file << Shopers[i].Cart_counter << "\n";
            if (Shopers[i].Cart_counter > 0) {
                Shopers_file << endl;
                if (Carts_file.is_open()) {
                    Carts_file << Shopers[i].id << endl;
                    for (int j = 0; j < Shopers[i].Cart_counter; j++)
                    {
                        Carts_file << Shopers[i].cart[j] << "\n";
                    }
                }
            }
        }
        Shopers_file.close();
        Carts_file.close();
    }
    ofstream Owners_file("Owners.txt");
    Owners_file.trunc;
    if (Owners_file.is_open()) {
        for (int i = 0; i < Owners_counter; i++)
        {
            Owners_file << Owners[i].id << "\n";
            Owners_file << Owners[i].name << "\n";
            Owners_file << Owners[i].age << "\n";
            Owners_file << Owners[i].address << "\n";
            Owners_file << Owners[i].gender << "\n";
            Owners_file << Owners[i].password << "\n";
            Owners_file << Owners[i].shop_name << "\n";
            Owners_file << Owners[i].address_shop << "\n";
            Owners_file << Owners[i].category_shop << "\n";
        }
        Owners_file.close();
    }
    ofstream Products_file("Products.txt");
    Products_file.trunc;
    if (Products_file.is_open()) {
        for (int i = 0; i < Products_counter; i++)
        {
            Products_file << products[i].Product_code << "\n";
            Products_file << products[i].product_name << "\n";
            Products_file << products[i].Shop_Owner_ID << "\n";
            Products_file << products[i].category << "\n";
            Products_file << products[i].price << "\n";
            Products_file << products[i].quantity << "\n";
        }
        Products_file.close();
    }
}
void Read_file() {
    ifstream Shopers_File("Shopers.txt");
    if (Shopers_File.is_open()) {
        string Line;
        Shopper shopper1;
        while (getline(Shopers_File, Line)) {
            shopper1.id = Line;
            getline(Shopers_File, Line);
            shopper1.name = Line;
            getline(Shopers_File, Line);
            shopper1.age = Line;
            getline(Shopers_File, Line);
            shopper1.address = Line;
            getline(Shopers_File, Line);
            shopper1.gender = Line;
            getline(Shopers_File, Line);
            shopper1.password = Line;
            getline(Shopers_File, Line);
            shopper1.Cart_counter = stoi(Line);
            if (shopper1.Cart_counter > 0) {
                ifstream Carts_File("Carts.txt");
                if (Carts_File.is_open()) {
                    while (getline(Carts_File, Line)) {
                        if (Line == shopper1.id) {
                            for (int i = 0; i < shopper1.Cart_counter; i++) {
                                getline(Carts_File, Line);
                                shopper1.cart[i] = Line;
                            }
                            break;
                        }
                    }
                }
            }
            expand_shopers();
            Shopers[Shopers_counter] = shopper1;
            Shopers_counter++;
        }
        Shopers_File.close();
    }
    ifstream Owners_File("Owners.txt");
    if (Owners_File.is_open()) {
        string Line;
        Shop_Owner shop_owner1;
        while (getline(Owners_File, Line)) {
            shop_owner1.id = Line;
            getline(Owners_File, Line);
            shop_owner1.name = Line;
            getline(Owners_File, Line);
            shop_owner1.age = Line;
            getline(Owners_File, Line);
            shop_owner1.address = Line;
            getline(Owners_File, Line);
            shop_owner1.gender = Line;
            getline(Owners_File, Line);
            shop_owner1.password = Line;
            getline(Owners_File, Line);
            shop_owner1.shop_name = Line;
            getline(Owners_File, Line);
            shop_owner1.address_shop = Line;
            getline(Owners_File, Line);
            shop_owner1.category_shop = Line;
            expand_owners();
            Owners[Owners_counter] = shop_owner1;
            Owners_counter++;
        }
        Owners_File.close();
    }
    ifstream Products_File("Products.txt");
    if (Products_File.is_open()) {
        string Line;
        Product product1;
        while (getline(Products_File, Line)) {
            product1.Product_code = Line;
            getline(Products_File, Line);
            product1.product_name = Line;
            getline(Products_File, Line);
            product1.Shop_Owner_ID = Line;
            getline(Products_File, Line);
            product1.category = Line;
            getline(Products_File, Line);
            product1.price = stof(Line);
            getline(Products_File, Line);
            product1.quantity = stoi(Line);
            expand_products();
            products[Products_counter] = product1;
            Products_counter++;
        }
        Products_File.close();
    }
}
void GetOwnerProducts() {
    string ID;
    cout << "ID : ";
    cin >> ID;
    vector <Product> Owner_Products;
    for (int i = 0; i < Products_counter; i++) {
        if (products[i].Shop_Owner_ID == ID) {
            Owner_Products.push_back(products[i]);
        }
    }
    for (int i = 0; i < Owner_Products.size(); i++) {
        cout << "Code : ";
        cout << Owner_Products[i].Product_code << endl;
        cout << "Name : ";
        cout << Owner_Products[i].product_name << endl;
        cout << "Price : ";
        cout << Owner_Products[i].price << endl;
        cout << "Quantity : ";
        cout << Owner_Products[i].quantity << endl;
        cout << "Category : ";
        cout << Owner_Products[i].category << endl;
    }
}
void Display_All_Products()
{
    if (Products_counter > 0) {
        cout << "Name\t Price\t Category\t Code\n";
        for (int i = 0; i < Products_counter; i++) {
            if (products[i].quantity > 0) {
                cout << products[i].product_name << "\t" << products[i].price << " LE\t" << products[i].category << products[i].Product_code;
            }
        }
    }
}
bool Shoper_Is_Found(string id) {
    for (int i = 0; i < Shopers_counter; i++) {
        if (Shopers[i].id == id)
            return true;
    }
    return false;
}

bool Owner_Is_Found(string id) {
    for (int i = 0; i < Owners_counter; i++) {
        if (Owners[i].id == id)
            return true;
    }
    return false;
}

bool Product_Is_Found_in_Store(string product_Code) {
    for (int i = 0; i < Products_counter; i++) {
        if (products[i].Product_code == product_Code)
            return true;
    }
    return false;
}
bool Product_Is_Found_in_Cart(string product_Code) {
    for (int i = 0; i < Shopers[index].Cart_counter; i++) {
        if (Shopers[index].cart[i] == product_Code)
            return true;
    }
    return false;
}
void edit_shopper()
{
    cout << "Name : ";
    cin >> Shopers[index].name;
    cout << "Password : ";
    cin >> Shopers[index].password;
    cout << "Gender : ";
    cin >> Shopers[index].gender;
    cout << "Address : ";
    cin >> Shopers[index].address;
    cout << "Age : ";
    cin >> Shopers[index].age;
    Save();
}
void edit_products()
{
    string Product_code;
    getline(cin, Product_code);
    for (int i = 0; i < Products_counter; i++)
    {
        if (products[i].Product_code == Product_code)
        {
            cout << "Name : ";
            cin >> products[i].product_name;
            cout << "Quantity : ";
            cin >> products[i].quantity;
            cout << "Price : ";
            cin >> products[i].price;
            break;
        }
    }
}

void Add_newowner()
{
    string id;
    Shop_Owner shop_owner;
    cout << "Please Enter ID : ";
    cin >> id;
    if (!Owner_Is_Found(id)) {
        expand_owners();
        shop_owner.id = id;
        cout << "Please Enter Name : ";
        cin >> shop_owner.name;
        cout << "Please Enter Password : ";
        cin >> shop_owner.password;
        cout << "Please Enter Gender : ";
        cin >> shop_owner.gender;
        cout << "Please Enter Address : ";
        cin >> shop_owner.address;
        cout << "Please Enter Shop Name : ";
        cin >> shop_owner.shop_name;
        cout << "Please Enter Shop Address : ";
        cin >> shop_owner.address_shop;
        cout << "Please Enter Shop Category : ";
        cin >> shop_owner.category_shop;
        cout << "Please Enter Age : ";
        cin >> shop_owner.age;
        Owners[Owners_counter] = shop_owner;
        index = Owners_counter;
        Owners_counter++;
        Save();
        cout << "\t\tWelcome " << Owners[index].name << endl;
    }
    else {
        cout << "This ID Is Already Exist !!\n";
    }

}
void Add_newshopper()
{
    string id;
    cout << "Please Enter ID : ";
    cin >> id;
    if (!Shoper_Is_Found(id)) {
        expand_shopers();
        Shopers[Shopers_counter].id = id;
        cout << "Name : ";
        cin >> Shopers[Shopers_counter].name;
        cout << "Password : ";
        cin >> Shopers[Shopers_counter].password;
        cout << "Gender : ";
        cin >> Shopers[Shopers_counter].gender;
        cout << "Address : ";
        cin >> Shopers[Shopers_counter].address;
        cout << "Age : ";
        cin >> Shopers[Shopers_counter].age;
        Shopers[Shopers_counter].Cart_counter = 0;
        index = Shopers_counter;
        Shopers_counter++;
        Save();
        cout << "\t\tWelcome " << Shopers[index].name << endl;
        cout << "\tNotice : Maximum Products can your Cart Hold is 10 Products :)\n";
    }
    else {
        cout << "ID Is Already Exist !!" << endl;
    }
}
void Add_newproduct()
{
    string product_code;
    cout << "Product code : ";
    cin >> product_code;
    if (!Product_Is_Found_in_Store(product_code)) {
        expand_products();
        products[Products_counter].Product_code = product_code;
        cout << "Name : ";
        cin >> products[Products_counter].product_name;
        products[Products_counter].Shop_Owner_ID = Owners[index].id;
        cout << "Category : ";
        cin >> products[Products_counter].category;
        cout << "Price : ";
        cin >> products[Products_counter].price;
        cout << "Quantity : ";
        cin >> products[Products_counter].quantity;
        Products_counter++;
        Save();
        cout << "The Product Is Added Successfully\n";
    }
    else {
        cout << "Product is already Exist !!\n";
    }
}
void delete_Product() {
    string code;
    bool is_mine = false;
    cout << "Product Code : ";
    cin >> code;
    int i;
    for (i = 0; i < Products_counter; i++) {
        if (code == products[i].Product_code)
        {
            if (products[i].Shop_Owner_ID == Owners[index].id) {
                cout << "Please enter Your Password Again : ";
                cin >> code;
                if (Owners[index].password == code) {
                    is_mine = true;
                }
                else {
                    cout << "Wrong Password !!\n";
                }
            }
            else {
                cout << "This Product is not yours !!\n";
            }
            break;
        }
    }
    if (is_mine) {
        for (int j = i + 1; j < Products_counter; j++) {
            products[i] = products[j];
            i++;
        }
        Products_counter--;
        Save();
        cout << "The Product Is Deleted Successfully\n";
    }
}
bool Is_Name(string X, string Y) {
    if (Y.size() <= X.size()) {
        transform(Y.begin(), Y.end(), Y.begin(), ::tolower);
        transform(X.begin(), X.end(), X.begin(), ::tolower);
        for (int i = 0; i < X.size(); i++) {
            if (X.size() - i >= Y.size()) {
                if (Y == X.substr(i, Y.size())) {
                    return true;
                }
            }
            else {
                return false;
            }
        }
    }
    return false;
}
void Search() {
    string product_name;
    cout << "Please Enter Name : ";
    cin >> product_name;
    int c = 0;
    for (int i = 0; i < Products_counter; i++) {
        if (Is_Name(products[i].product_name, product_name)) {
            cout << "Product " << c + 1 << " : " << endl;
            cout << "Product Code : " << products[i].Product_code << endl;
            cout << "Name : " << products[i].product_name << endl;
            cout << "Price : " << products[i].price << endl;
            cout << "Category : " << products[i].category << endl;
            c++;
        }
    }
}
void Remove_Product_from_Cart() {
    if (Shopers[index].Cart_counter > 0) {
        cout << "  Product Code\tProduct Name\tPrice\tCategory\n";
        for (int i = 0; i < Shopers[index].Cart_counter; i++) {
            for (int j = 0; j < Products_counter; j++) {
                if (Shopers[index].cart[i] == products[j].Product_code) {
                    cout << i + 1 << "- " << products[j].Product_code << "\t" << products[j].product_name << "\t" << products[j].price << "\t" << products[j].category << "\n";
                }
            }
        }
        cout << "  Your Receipt is " << Shopers[index].Receipt << endl;
    }
    string Product_ID;
    cout << "Product Code : ";
    cin >> Product_ID;
    if (Product_Is_Found_in_Cart(Product_ID)) {
        int i;
        for (i = 0; i < Shopers[index].Cart_counter; i++) {
            if (Shopers[index].cart[i] == Product_ID)
                break;
        }
        for (int j = i + 1; j < Shopers[index].Cart_counter; j++) {
            Shopers[index].cart[i] = Shopers[index].cart[j];
            i++;
        }
        Shopers[index].Cart_counter--;
        for (i = 0; i < Products_counter; i++) {
            if (products[i].Product_code == Product_ID) {
                products[i].quantity++;
            }
        }
        Save();
        cout << "Product Is Removed Successfully\n";
    }
}
void Add_Product_to_Cart() {
    string Product_Id;
    cout << "Please Enter Product ID : ";
    cin >> Product_Id;
    if (Product_Is_Found_in_Store(Product_Id))
    {
        if (Shopers[index].Cart_counter < 9)
        {
            for (int j = 0; j < Products_counter; j++)
            {
                if (products[j].Product_code == Product_Id) {
                    if (products[j].quantity > 0) {
                        Shopers[index].cart[Shopers[index].Cart_counter] = products[j].Product_code;
                        Shopers[index].Cart_counter++;
                        Shopers[index].Receipt = 0;
                        Shopers[index].Receipt += products[j].price;
                        products[j].quantity--;
                        Save();
                        cout << "The Product Is Added To Your Cart\nYour Receipt is " << Shopers[index].Receipt << endl;
                        break;
                    }
                    else {
                        cout << "The Product Quantity is Zero !!\n";
                        break;
                    }
                }
            }
            int number;
            cout << "Please Enter : (1)To remove a product from your cart\t (2)To confirm your purchase\t (0)To Exit\n";
            cin >> number;
            while (number != 0)
            {
                switch (number)
                {
                case 1: Remove_Product_from_Cart();
                    break;
                case 2: Shopers[index].Cart_counter = 0;
                    cout << "Buying is successed";
                    break;
                default: cout << "You entered an invalid input ";
                }
            }
        }
        else
        {
            cout << "Your have no space in your cart\n";
        }
    }
    else {
        cout << "Wrong Product Code\n";
    }
    Save();
}
bool Login_shoppers()
{
    cout << "Please Enter ID : ";
    string id;
    cin >> id;
    if (Shoper_Is_Found(id)) {
        string password;
        for (int i = 0; i < Shopers_counter; i++)
        {
            if (Shopers[i].id == id)
            {
                bool c = false;
                while (true)
                {
                    cout << "Please Enter the Password : ";
                    cin >> password;
                    if (Shopers[i].password == password)
                    {
                        index = i;
                        cout << "Welcome " << Shopers[i].name << endl;
                        return true;
                    }
                    else
                    {
                        cout << "You Entered a Wrong Password !!\n ";
                    }
                }
            }

        }
    }
    else {
        cout << "Wrong ID !!\n";
        return false;
    }
}

bool Login_owner()
{
    cout << "Please Enter ID : ";
    string id;
    cin >> id;
    if (Owner_Is_Found(id)) {
        string password;
        for (int i = 0; i < Owners_counter; i++)
        {
            if (Owners[i].id == id) {
                bool c = false;
                while (true) {
                    cout << "Please Enter the Password : ";
                    cin >> password;
                    if (Owners[i].password == password)
                    {
                        index = i;
                        return true;
                    }
                    else
                    {
                        cout << "You Entered a Wrong Password !!\n";
                    }
                }
            }

        }
    }
    else {
        cout << "Wrong ID !!\n";
        return false;
    }
}

int main()
{
    initializefunc();
    Read_file();
    int num = 10;
    while (num != 0) {
        cout << "Please Enter : (1)Sign In\t(2)Sign Up\n\t (0)Exit : ";
        cin >> num;
        switch (num) {
        case 0:
            break;
        case 1:
            cout << "Please Enter : (1) Shopper\t(2) Shop Owner\n\t (0) Exit : ";
            cin >> num;
            switch (num) {
            case 0:
                break;
            case 1:
                cout << "\t\tLogin Screen for Shopper \n";
                if (Login_shoppers())
                {
                    cout << "Please Enter : (1)Buy Product\t(2)Search For a Product\t(3)View Products information\t(4)Skip : ";
                    cin >> num;
                    switch (num) {
                    case 1:
                        Add_Product_to_Cart();
                        break;
                    case 2:
                        Search();
                        break;
                    case 3:
                        Display_All_Products();
                        break;
                    case 4:
                        break;
                    default:break;
                    }
                    cout << "Please Enter : (1)Edit Your Data\t(0)Exit : ";
                    cin >> num;
                    switch (num) {
                    case 1:
                        edit_shopper();
                        break;
                    case 0:
                        break;
                    default:break;
                    }
                }
                break;
            case 2:
                cout << "\t\t Login Screen for Shop Owner \n";
                if (Login_owner()) {
                    cout << "Please Enter : (1)Edit Data\t(2)Add new Product\t(3)Remove product\t(4)View all shop products\t(5)6-Edit data of product\t(0)Exit : ";
                    cin >> num;
                    string product_code;
                    switch (num)
                    {
                    case 1:
                        Edit_Owner();
                        break;
                    case 2:
                        Add_newproduct();
                        break;
                    case 3:
                        delete_Product();
                        break;
                    case 4:
                        GetOwnerProducts();
                        break;
                    case 5:
                        edit_products();
                        break;
                    case 0:
                        break;
                    default:
                        break;
                    }
                }
                break;
            default:
                cout << "\t\t Error Input\n";
                break;
            }
            break;
        case 2:
            cout << "Please Enter : (1)Shopper\t\t(2)Shop Owner" << endl;
            cin >> num;
            switch (num) {
            case 1:
                cout << "\t\t Sign UP Screen for Shopper \n";
                Add_newshopper();
                break;
            case 2:
                cout << "\t\t Sign UP Screen for Shop Owner \n";
                Add_newowner();
                break;
            default:
                cout << "\t\t Error Input\n";
                break;
            }
            break;
        default:
            cout << "\t\t Error Input\n";
            break;
        }
    }
    return 0;
}