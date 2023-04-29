#include <iostream>
#include <vector>

struct LOGIN_INFO{
    std::string login;
    std::string password;
    std::string phone_number;
};

bool is_string_size_equal(const std::string& str1, const std::string& str2){
    if(str1.length()==str2.length()){
        return true;
    }
    return false;
}

std::string xor_string(const std::string& str1, const std::string& str2){
    std::string result;
    result=std::to_string(std::min(str1.length(), str2.length()));
    for(size_t i=0; i<result.length(); ++i){
        result+=(char)(str1[i]^str2[i]);
    }
    return result;
}

int main() {
    std::vector<LOGIN_INFO> data_base;
    int i=0;

    while(true){
        LOGIN_INFO buffer_info;
        std::cout<<"Login (maximum 10 symbols): ";
        std::cin>>buffer_info.login;
        std::cout<<"password(maximum 20 symbols): ";
        std::cin>>buffer_info.password;
        std::cout<<"phone number: ";
        std::cin>>buffer_info.phone_number;
        data_base.push_back(buffer_info);

        if(data_base[i].login.size()>10 || data_base[i].password>20){
            std::cout<<"Your login or password is too long. True to register again."<<std::endl;
            continue;
        }

        if(data_base[i].login.empty() || data_base[i].password.empty() || data_base[i].phone_number.empty()){
            data_base[i].login.clear();
            data_base[i].password.clear();
            data_base[i].phone_number.clear();
            continue;
        }
        std::cout<<data_base[i].login<<" "<<data_base[i].password<<" "<<data_base[i].phone_number;
        ++i;
        break;
    }
}
