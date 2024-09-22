#include <iostream>
#include <string>
#include <vector>
#include <map>

class Stack {
private:
    std::vector<std::string> data;
public:
    void push(std::string element) {
        data.push_back(element);
    }
    std::string pop(){
        if(data.empty() == false){
            std::string popped = data.back();
            data.pop_back();
            return popped;
        }else{
            return 0;
        }
    }
    size_t size() const {
        return data.size();
    }
};
std::string TemplateStack(Stack temp){
    int length = temp.size();
    std::string resultString = "";
    for(int i = 1; i <= length; i++){
        resultString += temp.pop();
    }
    return resultString;
}
std::string decil_to_bases(int number, int bases){
    Stack temp;
    std::cout << std::endl << number << std::endl; ;
    switch(bases){
        case 2:
            while(number >= 2){
                int x = number % 2;
                std::cout << "------ " << x <<  std::endl;
                temp.push(std::to_string(x));
                number /= 2;
                std::cout << number << std::endl;
            }
            temp.push(std::to_string(number));
            break;

        case 8:
            while(number >= 8){
                int x = number % 8;
                std::cout << "------ " << x <<  std::endl;
                temp.push(std::to_string(x));
                number /= 8;
                std::cout << number << std::endl;
            }
            temp.push(std::to_string(number));
            break;

        case 16:
            std::string alphabet[] = {"A", "B", "C", "D", "E", "F", "G"};
            while(number >= 16){
                int x = number % 16;
                if(x < 10){
                    temp.push(std::to_string(x));
                    std::cout << "------ " << x <<  std::endl;
                }
                else{
                    temp.push(alphabet[x - 10]);
                    std::cout << "------ " << x << " = " << 
                    alphabet[x - 10] <<  std::endl;
                }
                number /= 16;
                std::cout << number << std::endl;
            }
            if(number < 10){
                temp.push(std::to_string(number));
                std::cout << std::endl;
            }
            else{
                temp.push(alphabet[number - 10]);
                std::cout << " = " << alphabet[number - 10] << std::endl;
            }
            break;
    }
    std::cout << "\n >> ";
    return TemplateStack(temp);
}

int main() {
    std::string log;
    while(log != "n"){
        int num;
        std::cout << "Number : ";
        std::cin >> num;
        std::cout << std::endl << "Binary : " << decil_to_bases(num, 2) << "\n\n";
        std::cout << "Octal : " << decil_to_bases(num, 8) << "\n\n";
        std::cout << "Hexal : " << decil_to_bases(num, 16) << "\n\n";
        std::cout << "Proceed? (Enter any character to continue OR enter n to abort) ";
        std::cin >> log;
        if(log == "n"){
            break;
        }
    }
    return 0;
}