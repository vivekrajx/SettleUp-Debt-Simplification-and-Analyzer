//Function to calculate expenses in our SettleUP Application
void calculate()
{
  MYSQL *conn;
  MYSQL_ROW row;
  MYSQL_RES *res;
  conn = mysql_init(0);

  conn = mysql_real_connect(conn, "localhost", "root", "password", "database_name", 3306, NULL, 0);
  string test_query1 = "CREATE TABLE TABLE_NAME(Item varchar(20), amount INT)";
  const char *q = test_query1.c_str();
  qstate = mysql_query(conn, q);

  for (int i = 0; i < 5; i++)
  {
    string Item, amount;
    cin >> Item >> amount;
    cout << Item << amount << endl;
    string test_query1 = "INSERT INTO TABLE_NAME (Item, amount) VALUES('" + Item + "','" + amount + "')";
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
        printf("Item: %s, Amount: %s\n", row[0], row[1]);
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
}
//Function to update the dataset in our SettleUp Application
void update()
{
  MYSQL *conn;
  MYSQL_ROW row;
  MYSQL_RES *res;
  conn = mysql_init(0);
  conn = mysql_real_connect(conn, "localhost", "root", "password", "database_name", 3306, NULL, 0);
  const char *q = test_query2.c_str();
  qstate = mysql_query(conn, q);
}
