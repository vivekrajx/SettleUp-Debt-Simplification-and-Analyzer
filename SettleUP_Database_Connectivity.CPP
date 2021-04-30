#include <mysql.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int qstate;

int main()
{
	MYSQL *conn;
	MYSQL_ROW row;
	MYSQL_RES *res;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "root", "password", "testdb2", 3306, NULL, 0);

	int N;
	cout << "Enter number of items : ";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string Item, amount;
		cout << "Item Name: ";
		cin >> Item;
		cout << "Amount: ";
		cin >> amount;
		// << Item << amount << endl;
		string test_query1 = "INSERT INTO EXPENSES (Item, amount) VALUES('" + Item + "','" + amount + "')";
		//cout << insert_query1;
		const char *q = test_query1.c_str();
		qstate = mysql_query(conn, q);
	}

	if (conn)
	{
		puts("Successful connection to database!");

		string query = "SELECT * FROM EXPENSES";
		const char *q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				printf("ID: %s, Name: %s, Value: %s\n", row[0], row[1], row[2]);
			}
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
		}
	}
	else
	{
		puts("Connection to database has failed!");
	}

	return 0;
}
