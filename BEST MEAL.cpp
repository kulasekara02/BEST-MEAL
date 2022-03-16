#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;
//declare user define functions

void Start_Page();
bool login();
bool userdata();
void main_menu(string customer = "");
void cal_bill(string);
void addcu();
void help();
void exit();
void saveOrderInfo(string, char*, string, int, string, int, int, int);

char username[30];
int password;
//c///
int main()
{
    Start_Page();

    int invalidAttempts = 0;
    while (!login())
    {
        system("cls");
        invalidAttempts++;
        if (invalidAttempts >= 3)
        {
            return 0;
        }
        cout << "ERROR ! you have entered worng password or user name\n" << endl;
    }


    main_menu();

}

//                 MAIN STARTING PAGE

void Start_Page()
{

    cout << "\n" << endl;
    cout << "            ***************************************************                " << endl;
    cout << "                                                                               " << endl;
    cout << "\n";
    cout << "     |||| _ _ _ _ _ _ _ _ _    BEST MEAL    _ _ _ _ _ _ _ _ _||||               " << endl;
    cout << "\n";
    cout << "\n";
    cout << "                  # # # #  W  E  L  C  O  M  E  # # # #                         " << endl;
    cout << "\n";
    cout << "                                                                               " << endl;
    cout << "                                                                               " << endl;
    cout << "            ***************************************************                " << endl;

    system("pause");
    system("cls");
}

bool login()
{
    //greeting
    cout << "                              *****************                                " << endl;
    cout << "                                                                               " << endl;
    cout << "  ---------------------_ _ _ _ _  BEST MEAL  _ _ _ _ _ -------------------     " << endl;
    cout << "\n";
    cout << "          _ _ _ _ _ _ _ _ _ O R D E R I N G  S Y S T E M_ _ _ _ _ _ _ _ _        " << endl;

    cout << "\n";
    cout << "Please login to proceed !";
    cout << "\n";

    return userdata();
}
/// login function
bool userdata()
{
    cout << "\n";
    cout << " \tEnter your Username :- ";
    cin >> username;
    cout << "\tEnter your Password :- ";
    cin >> password;
    system("cls");

    return (string(username) == "ADMIN" && password == 1234);
}
//display the ALL  available main functions
void main_menu(string customer)
{
    system("cls");
    int N;
    cout << "            ***************************************************                " << endl;
    cout << "                                                                               " << endl;
    cout << "\n";
    cout << "     |||| _ _ _ _ _ _ _ _ _   BEST MEAL     _ _ _ _ _ _ _ _ _||||               " << endl;
    cout << "\n";
    cout << "\n";
    cout << "                  # # # #  W  E  L  C  O  M  E  # # # #                         " << endl;
    cout << "\n";
    cout << "            _________________________________________________                " << endl;
    cout << "\n";

    cout << "		   	(1) - ADD CUSTOMER                                        " << endl;
    cout << "                                                                    " << endl;
    cout << "			(2) - CALCULATE BILL                                     " << endl;
    cout << "                                                                    " << endl;
    cout << "           \t\t(3) - HELP                                               " << endl;
    cout << "                                                                    " << endl;
    cout << "           \t\t(4) - EXIT                                           " << endl;
    cout << "																	 " << endl;
    cout << "		Enter the option number :-	";
    cin >> N;
    cout << "\n" << endl;
    system("cls");
    ////////switch case statement
    switch (N)
    {
        case 1:
            addcu();
            system("cls");

        case 2:
            cal_bill(customer);

        case 3:
            help();

        case 4:
            exit();
            break;
        default:
            cout << "Invalid Option" << endl;

            main_menu();

    }
}

void saveCustomerInfo(int customerID, string const& customerName, string const& customerAddress, long telephoneNumber)
{
    ofstream outfile;
    outfile.open((customerName + ".txt").c_str(), ios::out | ios::trunc);

    outfile << "            ***************************************************                " << endl;
    outfile << "                                                                               " << endl;
    outfile << "\n";
    outfile << "     |||| _ _ _ _ _ _ _ _ _   BEST MEAL    _ _ _ _ _ _ _ _ _||||               " << endl;
    outfile << "\n";
    outfile << "\n";

    outfile << "Customer Name       : " << customerName << endl;
    outfile << "customer  ID     	: " << customerID << endl;
    outfile << "Customer Address    : " << customerAddress << endl;
    outfile << "Telephone Number    : " << telephoneNumber << endl;

    outfile.close();
}




void saveOrderInfo(string customerName, char* buffer, string pname, int package, string intpackagename, int intpackage, int extrap, int extraMEALcal)
{
    ofstream outfile;
    outfile.open((customerName + ".txt").c_str(), std::ios_base::app);

    outfile << "            ***************************************************                " << endl;
    outfile << "                                                                               " << endl;
    outfile << "BEST MEAL" << "                                                 " << "Billing date : " << buffer << endl;
    outfile << "BEST MEAL" << "                                             " << "Billing period:01/10/2020 - 31/11/2020" << endl;
    outfile << "Flower Road,Colombo-03" << "                                " << "Customer Account Number-CUS001" << endl;
    outfile << " " << endl;
    outfile << " " << endl;
    outfile << "NUG24489658                                                                  (RS.)" << endl;
    outfile << " " << endl;
    outfile << "BEST MEAL TYPE " << pname <<"                                                "<< package << ".00" << endl;
    outfile << " " << endl;
    outfile << "BEST MEAL " << intpackagename <<"                                            "<< intpackage << ".00" << endl;
    outfile << " " << endl;
    outfile << "PERSON------------------------(" << extrap << ")                             " << extraMEALcal << ".00" << endl;
    outfile << " " << endl;

    outfile << "__________________________________________________________________________________________" << endl;

    int total = (package + intpackage * extrap   );

    outfile << "Total Charges                                           " << total << ".00" << endl;
    outfile << "__________________________________________________________________________________________" << endl;
    outfile << " " << endl;
    outfile << "\n";
    outfile << " 			THANK YOU FOR USING BEST MEAL			" << endl;


    outfile.close();
}


void addcu()
{

    int cid;
    string name;
    string add;
    long tele;
    string cotype;
    string intype;

    cout << "            ***************************************************                " << endl;
    cout << "                                                                               " << endl;
    cout << "\n";
    cout << "     |||| _ _ _ _ _ _ _ _ _     BEST MEAL    _ _ _ _ _ _ _ _ _||||               " << endl;
    cout << "\n";

    cout << "     |||| _ _ _ _ _ _ _ _ _    ADD MEALS  _ _ _ _ _ _ _ _ _||||               " << endl;
    cout << "\n";
    cout << " " << endl;

    cout << "\tEnter CUSTOMER ID No:\t";
    cin >> cid;

    cout << "\tCustormer Name:\t";
    cin >> name;

    cout << "\tCustormer Address:\t";
    cin >> add;

    cout << "\tTelephone Number:\t";
    cin >> tele;
    cout << "  " << endl;

    saveCustomerInfo(cid, name, add, tele);

    int n;
    cout << "\t\tmain menu :- (1)" << endl;
    cout << "\n";
    cin >> n;


    if (n == 1)
    {
        main_menu(name);
        system("cls");
    }
}
/////////calculation part
void cal_bill(string customer)
{

    int total = 0;
    int package = 0;
    int intpackage = 0;
    string intpackagename = "";
    string pname = "";
    string choice = "";
    string choice2 = "";
    string choice3 = "";
    int Counter = 0;
    int extra = 50;
    int extrap;
    int tax = 474;
    int extraMEALcal = 0;
    //
    {

        cout << "           ***************************************************                " << endl;
        cout << "                                                                               " << endl;
        cout << "\n";
        cout << "     |||| _ _ _ _ _ _ _ _ _    BEST MEAL    _ _ _ _ _ _ _ _ _ ||||               " << endl;
        cout << "\n";


        cout << "_____________ MEAL PACKAGES ____________" << endl;
        cout << " " << endl;
        cout << "Type A - BREAKFAST      Rs.410.00      " << endl;
        cout << "Type B - LUNCH          Rs.750.00      " << endl;
        cout << "Type C - DINNER         Rs.1000.00     " << endl;
        cout << " " << endl;
        cout << "PLEASE CHOOSE YOUR MEAL PACKAGE" << endl;
        cout << " " << endl;
        cin >> choice;
        // selecting the package
        //{
        if (choice == "A")
        {
            package = 410.00;
        }
        else if (choice == "B")
        {
            package = 750.00;
        }
        else if (choice == "C")
        {
            package = 1000.00;
        }
        //	}
        //	{
        if (choice == "A")
        {
            pname = "BREAKFAST";
        }
        else if (choice == "B")
        {
            pname = "LUNCH";
        }
        else if (choice == "C")
        {
            pname = "DINNER";
        }
        //	}

        cout << " " << endl;
        cout << " " << endl;
        cout << ".......................MEAL PACKAGES....................... " << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "A -- NORMAL BREAKFAST    " << endl;
        cout << " " << endl;
        cout << "    PRICE - Rs.1499.00     " << endl;
        cout << "    Instant Pot Oatmeal    " << endl;
        cout << "    Avocado Toast - (up to) 21 Mbps    " << endl;
        cout << "    Cottage Cheese and Fruit.    " << endl;
        cout << "    Scrambled eggs with salsa   " << endl;
        cout << "    Bananas and peanut butter (or nutella)    " << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "B -- PREMIUM BREAKFAST    " << endl;
        cout << " " << endl;
        cout << "    Monthly Rental - Rs 2500.00 " << endl;
        cout << "    Aromatic stir fried pork" << endl;
        cout << "    Chicken, with chorizo and bean casserole " << endl;
        cout << "    Spinach and ricotta cannelloni" << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "C -- NORMAL LUNCH    " << endl;
        cout << " " << endl;
        cout << "    PRICE - Rs.1890.00    " << endl;
        cout << "    Vegetable Grits   " << endl;
        cout << "    Salad with Chicken, Cheese, Carrots, Hummus, and Crackers " << endl;
        cout << "    Chopped Quinoa Salad with Cranberries    " << endl;
        cout << "    RICE    " << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "D -- PREMIUM LUNCH    " << endl;
        cout << " " << endl;
        cout << "    PRICE  - Rs 2590.00" << endl;
        cout << "    Green Chile Enchilada" << endl;
        cout << "    Easy Tomato Soup" << endl;
        cout << "    Grilled Cheese BLT  " << endl;
        cout << "    Turkey Tetrazzini " << endl;
        cout << "    Mexican Tostada " << endl;
        cout << "    RICE " << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "E -- NORMAL DINNER    " << endl;
        cout << " " << endl;
        cout << "    PRICE - Rs.2590.00    " << endl;
        cout << "    Pulled Pork with Cornbread Topping " << endl;
        cout << "    Chicken Paprikash" << endl;
        cout << "    Ginger Pork & Cabbage Stir-Fry   " << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "F -- PREMIUM DINNER    " << endl;
        cout << " " << endl;
        cout << "    PRICE  - Rs 3590.00" << endl;
        cout << "   Shrimp Noodle Salad with Peanut Sauce. Farro & Sausage Stew" << endl;
        cout << "    Farro & Sausage Stew. Pork & Potato Green Chili" << endl;
        cout << "    Pork & Potato Green Chile. Spicy Chicken & Broccoli " << endl;

        cout << " " << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "     PLEASE CHOOSE YOUR MEAL PAKEGE    " << endl;
        cin >> choice2;
        cout << "..............PERSON.............." << endl;
        cout << " " << endl;
        cout << "       1 PERSON                  "    << endl;
        cout << " " << endl;
        cout << "       2 PERSON                 "     << endl;
        cout << " " << endl;
        cout << "       3 PERSON                "      << endl;
        cout << " " << endl;
        cout << "       4 PERSON                "     << endl;
        cout << " " << endl;
        cout << "       5 PERSON              "   << endl;
        cout << " " << endl;
        cout << "       6 PERSON              "   << endl;
        cin >> extrap;
        cout << " " << endl;
        cout << " " << endl;
        //	{

        //selecting the main menu
        if (choice2 == "A")
        {
            intpackage = 1499;
            intpackagename = "NORMAL BREAKFAST";
            cout << " INPUT SELECTED PERSON AGAIN:";
            cin >> extrap;
        }
        else if (choice2 == "B")
        {
            intpackage = 2500;
            intpackagename = "PREMIUM BREAKFAST";
            cout << " INPUT SELECTED PERSON AGAIN:";
            cin >> extrap;
        }
        else if (choice2 == "C")
        {
            intpackage = 1890;
            intpackagename = "NORMAL LUNCH";
            cout << " INPUT SELECTED PERSON AGAIN:";
            cin >> extrap;
        }
        else if (choice2 == "D")
        {
            intpackage = 2590;
            intpackagename = "PREMIUM LUNCH";
            cout << " INPUT SELECTED PERSON AGAIN:";
            cin >> extrap;
        }
        else if (choice2 == "E")
        {
            intpackage = 2590;
            intpackagename = "NORMAL DINNER";
            cout << " INPUT SELECTED PERSON AGAIN:";
            cin >> extrap;
        }
        else if (choice2 == "F")
        {
            intpackage = 3590;
            intpackagename = "PREMIUM DINNER";
            cout << " INPUT SELECTED PERSON AGAIN:";
            cin >> extrap;
        }
        //	}
        //   adding the extra persons
        if (extrap == 0)
        {
            extraMEALcal = 0;
        }
        else if (extrap == 1)
        {
            extraMEALcal = 1;
        }
        else if (extrap == 2)
        {
            extraMEALcal = 2;
        }
        else if (extrap == 3)
        {
            extraMEALcal = 3;
        }
        else if (extrap > 4)
        {
            extraMEALcal = (extrap == 4);
        }
        else if (extrap > 5)
        {
            extraMEALcal = (extrap == 5);
        }
        else if (extrap > 6)
        {
            extraMEALcal = (extrap == 6);
        }
        //total =( package+intpackage*extra+extraGBcal);
        cout << " " << endl;
        cout << " " << endl;



        cout << " " << endl;
        cout << " " << endl;

        time_t now = time(0);

        char* buffer = ctime(&now);


        cout << " " << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "BEST MEAL" << "                                                 " << "Billing date : " << buffer << endl;
        cout << "BEST MEAL" << "                                             " << "Billing period:01/10/2020 - 31/11/2020" << endl;
        cout << "Flower Road,Colombo-03" << "                                " << "Customer Account Number-CUS001" << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "NUG24489658                                                                  (RS.)" << endl;
        cout << " " << endl;
        cout << "BEST MEAL TYPE " << pname <<"                                                "<< package << ".00" << endl;
        cout << " " << endl;
        cout << "BEST MEAL " << intpackagename <<"                                            "<< intpackage << ".00" << endl;
        cout << " " << endl;
        cout << "PERSON------------------------(" << extrap << ")                             " << extraMEALcal << ".00" << endl;
        cout << " " << endl;

        cout << "__________________________________________________________________________________________" << endl;

        total = (package + intpackage * extrap   );

        cout << "Total Charges                                           " << total << ".00" << endl;
        cout << "__________________________________________________________________________________________" << endl;
        cout << " " << endl;
        cout << "\n";
        cout << " 			THANK YOU FOR USING BEST MEAL			" << endl;



        saveOrderInfo(customer, buffer, pname, package, intpackagename, intpackage, extrap, extraMEALcal);

    }
}
//////////////exit process
void exit()
{

    char g;

    cout << "\n";
    cout << "do you really want to exit (y/n) ? ";
    cout << "\n";
    cin >> g;
    if (g == 'y' || g == 'Y')
    {
        cout << " you have logged out ! thank you " << endl;
    }

    else if (g == 'n' || g == 'Y')
    {
        main_menu();
        system("cls");
    }
    else
    {
        cout << " invalid input !" << endl;
        exit();
    }
}

void help()
{


    cout << "HELP \n\n";
    cout << "If you're having trouble accessing a  product, there's a chance we're currently experiencing a temporary problem. You can check for outages and downtime on the G Suite Status Dashboard.";

}
