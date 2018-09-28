#include "db_helper.h"
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;


MYSQL *getConnect(string host, int port, string user, string pwd, string db_name) {
    MYSQL *conn = mysql_init(NULL);
    conn = mysql_real_connect(conn, host.c_str(), user.c_str(), pwd.c_str(),
                              db_name.c_str(), port, NULL, CLIENT_FOUND_ROWS);
    if (conn) {
        printf("connect success!\n");
    }
    return conn;
}

DbHelper::DbHelper(const std::string &host, int port,
                   const std::string &user, const std::string &pwd,
                   const std::string &db_name) {
    host_ = host;
    port_ = port;
    user_ = user;
    pwd_ = pwd;
    dbName_ = db_name;
    conn_ = getConnect(host_, port_, user_, pwd_, dbName_);
}


DbHelper::~DbHelper() {

}


void DbHelper::queryFaceImgByAttribute(char *attribute, char *vaule, vector<FaceImg> *out) {

    /*这句话是设置查询编码为utf8，这样支持中文*/
    mysql_query(conn_, "set names utf8");
    // 拼接查询SQL
    char query_sql[300];

    sprintf(query_sql, "select * from face_img where %s = '%s' ", attribute, vaule);

    cout << query_sql << endl;
    //查询数据
    mysql_query(conn_, query_sql);

    MYSQL_RES *query_result;
    MYSQL_FIELD *field;
    MYSQL_ROW result_row;
    vector<FaceImg> res;

    query_result = mysql_store_result(conn_);
    //取得結果的行数和列数
    int column = mysql_num_fields(query_result);
    int row = mysql_num_rows(query_result);
    printf("查询到 %d 行 \n", row);

    //输出結果的字段名
    for (int i = 0; (field = mysql_fetch_field(query_result)); i++)
        printf("%s\t", field->name);
    printf("\n");
    //按行输出結果
    for (int i = 0; i < row; i++) {
        result_row = mysql_fetch_row(query_result);
        FaceImg temp;

        if (column != 4) {
            cout << column << endl;
            return;
        }

        temp.img_name = result_row[1];
        temp.gender = result_row[2];
        temp.smile = result_row[3];

        (*out).push_back(temp);
    }
    mysql_free_result(query_result);
}

void DbHelper::free() {
    mysql_close(conn_);
}