//
// An example from the web
// To make it work on voyager it must be compiled as such:
//
// g++ -Wall -o mysql_test -I/usr/include/mysql-cppconn-8/mysql -I/usr/include/mysql-cppconn-8/jdbc mysql_test.cpp -L/usr/lib64 -lmysqlcppconn 
//

// To use c++ libraries
#include <iostream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

// To use lambda anonymous functions in c++ programming 
#include <boost/lambda/lambda.hpp> 

// To create MySQL connections
#include "mysql_connection.h"

// To use SQL statements in c++
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#define HOST "localhost"
#define USER "laywood"
#define PASS "RejTL?MK"
#define DB   "laywood"

using namespace std;

int main(void)
{
    cout << "Select your choice:" << endl;
    cout << "1) Query 2: " << endl;
    cout << "2) Query 5: " << endl;
    cout << "3) Exit" << endl;

    bool check = true;
    int choice;
    string fName, lName;
    while (check) {
        cin >> choice;
        if (choice == 1 || choice == 2 || choice == 3) {
            check = false;
        }
        else {
            cout << endl << "Invalid input, please input a value 1-3" << endl;
        }
    }
    if (choice == 3) {
        return 0;
    }

    else if (choice == 1) {
        cout << "First Name?" << endl;
        cin >> fName;
        cout << "Last Name?" << endl;
        cin >> lName;

        try {
            sql::Driver* driver;
            sql::Connection* con;
            sql::ResultSet* res;
            sql::PreparedStatement* pstmt;

            // Create a connection
            driver = get_driver_instance();
            con = driver->connect(HOST, USER, PASS);

            // Connect to the MySQL database
            con->setSchema(DB);

            // Execute your SQL query

            //pstmt = con->prepareStatement("SELECT Fname, Lname FROM EMPLOYEE ORDER BY Fname ASC");
            pstmt = con->prepareStatement(
                "SELECT match_id AS \"Match ID\", match_kind AS \"Match Kind\", venue_venue_id AS \"Venue ID\", match_date AS \"Match Date\" "
                "FROM `match`, user, purchase, ticket "
                "WHERE user.user_id = purchase.user_user_id "
                "AND purchase.ticket_ticket_id = ticket.ticket_id "
                "AND ticket.match_match_id = `match`.match_id "
                "AND user.first_name = ? AND user.last_name = ? "
                "ORDER BY `match`.match_date DESC;"
            ));

            res = pstmt->executeQuery();

            // Fetch the results
            while (res->next()) {
                cout << "Match ID: " << res->getInt("Match ID") << ", ";
                cout << "Match Kind: " << res->getString("Match Kind") << ", ";
                cout << "Venue ID: " << res->getInt("Venue ID") << ", ";
                cout << "Match Date: " << res->getString("Match Date") << endl;
            }
            delete res;
            delete pstmt;
            delete con;

        }
        catch (sql::SQLException& e) {
            cout << "# ERR: " << e.what() << endl;
            cout << " (MySQL error code: " << e.getErrorCode();
            cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        }
    }
    else if (choice == 2) {
        try {
            sql::Driver* driver;
            sql::Connection* con;
            sql::ResultSet* res;
            sql::PreparedStatement* pstmt;

            // Create a connection
            driver = get_driver_instance();
            con = driver->connect(HOST, USER, PASS);

            // Connect to the MySQL database
            con->setSchema(DB);

            // Execute your SQL query

            //pstmt = con->prepareStatement("SELECT Fname, Lname FROM EMPLOYEE ORDER BY Fname ASC");
            pstmt = con->prepareStatement(
                "SELECT u.user_ID AS \"User ID\", u.first_name AS \"First Name\", u.last_name AS \"Last Name\" "
                "FROM user AS u "
                "JOIN ( "
                "    SELECT reservation.ticket_ticket_id, reservation.user_user_id "
                "    FROM reservation "
                "    JOIN ( "
                "        SELECT ticket.ticket_id "
                "        FROM ticket "
                "        WHERE ticket.match_match_id = 'M3' "
                "    ) AS m3Tickets "
                "    ON reservation.ticket_ticket_id = m3Tickets.ticket_id "
                ") AS reservedM3Tickets "
                "ON u.user_id = reservedM3Tickets.user_user_id "
                "LEFT JOIN purchase AS p "
                "ON reservedM3Tickets.ticket_ticket_id = p.ticket_ticket_id "
                "WHERE p.ticket_ticket_id IS NULL;"
            ));

            res = pstmt->executeQuery();

            // Fetch the results
            while (res->next()) {
                cout << "User ID: " << res->getInt("User ID") << ", ";
                cout << "First Name: " << res->getString("First Name") << ", ";
                cout << "Last Name: " << res->getString("Last Name") << endl;
            }
            delete res;
            delete pstmt;
            delete con;

        }
        catch (sql::SQLException& e) {
            cout << "# ERR: " << e.what() << endl;
            cout << " (MySQL error code: " << e.getErrorCode();
            cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        }
    }

    cout << "Done." << endl;

    return EXIT_SUCCESS;
}