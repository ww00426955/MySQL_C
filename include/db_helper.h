#include<stdio.h>
#include <string>
#include <mysql.h>
#include <vector>
#include <mutex>
#include <list>
#include <memory>
#include <condition_variable>

using namespace std;

struct FaceImg {
    char *img_name;
//    String img_root_path;

    char *gender;      // male female
    char *smile;       // yes no
//    string glass;       // none dark normal
//    string emotion;     // anger disgust fear happiness neutral sadness surprise
//    string ethnicity;   // asian white black
//    String age;            // [0-100]
//    String beauty;         // [0-100]
//    String pose_pitch;   // [-90-90]
//    String pose_yaw;     // [-90-90]
//    String pose_roll;    // [-90-90]
};

class DbHelper {
public:
    DbHelper(const std::string &host, int port, const std::string &user, const std::string &pwd,
             const std::string &db_name);

    ~DbHelper();

    void free();

    void queryFaceImgByAttribute(char *attribute, char *vaule, vector<FaceImg> *out);
    void insertFaceImg(vector<FaceImg> *in);

private:
    std::string host_;
    int port_;
    std::string user_;
    std::string pwd_;
    std::string dbName_;
    MYSQL *conn_;
};

