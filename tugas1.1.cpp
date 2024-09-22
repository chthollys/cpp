#include <iostream>
#include <math.h>
#include <string>
#include <format>
#include <vector>
#include <cmath>
#include <map>

void binaryCodex(std::string temp, int n, std::vector <std::string>& result){
    if (n == 0){
        result.push_back(temp);
    }
    else{
        std::string new_temp1 = temp + "0";
        std::string new_temp2 = temp + "1";
        binaryCodex(new_temp1, n - 1, result);
        binaryCodex(new_temp2, n - 1, result);
    }
}

std::map<std::string, std::string> dictionaryBinarytoBases(int bases){
    std::string alphabet[] = {"A", "B", "C", "D", "E", "F", "G"};
    std::map<std::string, std::string> dictionary;
    std::string temp = "";
    std::vector <std::string> result;
    binaryCodex(temp, static_cast<int> (log2(bases)), result);
    for(int i = 0; i < static_cast<int>(result.size()); i++){
        if(i <= 9){
            dictionary[result[i]] = std::to_string(i);
        }
        else{
            dictionary[result[i]] = alphabet[i-10];
        }
    }
    return dictionary;
}

std::map<char, std::string> dictionaryBasestoBinary(int bases){
    char alphabet[] = {'A','B','C', 'D', 'E', 'F', 'G'};
    std::map<char, std::string> dictionary;
    std::string key_name = "";
    std::vector <std::string> listofKey;
    binaryCodex(key_name, static_cast<int> (log2(bases)), listofKey);
    for(int i = 0; i < bases; i++){
        if(i <= 9){
            dictionary[i + '0'] = listofKey[i];
        }
        else{
            dictionary[alphabet[i-10]] = listofKey[i];
        }
        //std::cout << listofKey[i] << std::endl;
        
    }
    //std::cout << dictionary["A"] << std::endl;
    return dictionary;
}

int convertBases(std::string op){
    int bases;
    if(op == "binary"){
        bases = 2;
    }
    if(op == "octal"){
        bases = 8;
    }
    if(op == "decil"){
        bases = 10;
    }
    if(op == "hexa"){
        bases = 16;
    }
    return bases;
}

std::string TemplateArray(std::vector<std::string> temp){
    std::vector<std::string> result;
    int length = temp.size();
    std::string resultString = "";
    for(int i = 1; i <= length; i++){
        result.push_back(temp[length - i]);
    }
    for(std::string a : result){
        resultString += a;
    }
    return resultString;
}

std::vector <std::string> ReverseArray(std::vector<std::string> temp){
    std::vector<std::string> result;
    int length = temp.size();
    for(int i = 1; i <= length; i++){
        result.push_back(temp[length - i]);
    }
    return result;
}

std::string decil_to_bases(std::string num, int bases){
    int number = stoi(num, 0, 10);
    std::vector<std::string> temp;
    switch(bases){
        case 2:
            while(number > 1){
                int x = number % 2;
                if(x == 0){
                    temp.push_back("0");
                    //std::cout << "0" << std::endl;
                }
                else{
                    temp.push_back("1");
                    //std::cout << "1" << std::endl;
                }
                number /= 2;
            }
            if(number == 0){
                temp.push_back("0");
                //std::cout << "0" << std::endl;
            }
            else{
                temp.push_back("1");
                //std::cout << "1" << std::endl;
            }
            break;

        case 8:
            while(number > 7){
                int x = number % 8;
                temp.push_back(std::to_string(x));
                number /= 8;
            }
            temp.push_back(std::to_string(number));

            break;

        case 16:
            std::string alphabet[] = {"A", "B", "C", "D", "E", "F", "G"};
            while(number > 15){
                int x = number % 16;
                if(x < 10){
                    temp.push_back(std::to_string(x));
                }
                else{
                    temp.push_back(alphabet[x - 10]);
                }
                number /= 16;
            }
            if(number < 10){
                temp.push_back(std::to_string(number));
            }
            else{
                temp.push_back(alphabet[number - 10]);
            }
            break;
    }
    return TemplateArray(temp);
}

std::string FilteredDecompositionBasesofBinary(std::string num){
    //int base = log2(bases);
    std::vector <char> tempRaw;
    std::vector <std::string> tempUnfiltered0;
    std::vector <std::string> tempFiltered;
    std::string returnResult = "";
    bool settle;
    if(num[0] == '0'){
        settle = false;
    }
    else{
        settle = true;
    }
    for(char i : num){
        if(settle == false && i == '0'){
            continue;
        }
        else{
            settle = true;
            returnResult += i;
        }
    }
    return returnResult;
}

std::string bases_to_binary(std::string num, int bases){
    std::vector <char> decomp_Num(num.begin(), num.end());
    std::vector <std::string> temp;
    std::vector <std::string> tempFinale;
    std::string result = "";
    std::string resultReturn;
    std::map<char, std::string> dictionary = dictionaryBasestoBinary(bases);
    //std::cout << num << std::endl;
    /*for(auto k : decomp_Num){
            std::cout << k << "  ";
        }
    */
    switch(bases){
        case 10:
            resultReturn = decil_to_bases(num, 2);
            break;
        case 2:
            resultReturn = num;
            break;

        case 8:
            //std::cout << dictionary['3'] << "whattt" << std::endl;
            for(int i = 0; i < static_cast<int>(decomp_Num.size()); i++){
                temp.push_back(dictionary[decomp_Num[i]]);
            }
            for(std::string res : temp){
                //std::cout << res << "  ";
                result += res;
            }
            resultReturn = FilteredDecompositionBasesofBinary(result);
            //std::cout << resultReturn << std::endl;
            break;
        case 16:
            //std::cout << dictionary['3'] << " whattt" << std::endl;
            for(int i = 0; i < static_cast<int>(decomp_Num.size()); i++){
                temp.push_back(dictionary[decomp_Num[i]]);
            }
            for(std::string res : temp){
                //std::cout << res << "  ";
                result += res;
            }
            resultReturn = FilteredDecompositionBasesofBinary(result);
            //std::cout << std::endl << resultReturn << std::endl;
            //std::cout << resultReturn << std::endl;
            break;
            /*
            int modIndex = static_cast<int>(decomp_Num.size()) % base;
            int currentIndex = 0;
            if(modIndex != 0){
                std::string ref = "";
                for(int i = modIndex; i < base; i++){
                    ref += '0';
                }
                for(int j = 0; j < modIndex; j++){
                    ref += decomp_Num[j];
                }
                currentIndex += modIndex;
                temp.push_back(ref);
            }
            while(currentIndex < static_cast<int>(decomp_Num.size())){
                std::string reff = "";
                for(int i = 0; i < base; i++){
                    reff += decomp_Num[currentIndex + i];
                }
                currentIndex += base;
                temp.push_back(reff);
            }
            for(std::string a : temp){
                //std::cout << a << std::endl;
                tempFinale.push_back(dictionary[a]);
            }
            resultReturn = TemplateArray(tempFinale);
            break;
            */
    }
    return resultReturn;
}

std::string binary_to_bases(std::string num, int bases){
    std::map<std::string, std::string> dictionary8 = dictionaryBinarytoBases(8);
    std::map<std::string, std::string> dictionary16 = dictionaryBinarytoBases(16);
    std::vector <char> numstr;
    std::string finaleResult;
    std::vector <std::string> decomp_Num;
    std::vector <std::string> temp;
    std::vector <std::string> tempFinale;
    long long int result = 0;
    int base = static_cast<int>(log2(bases));
    int curr = 0;
    //std::cout << num << std::endl;
    for(char i : num){
        //std::cout << i << "  ";
        std::string j(1, i);
        decomp_Num.emplace_back(j);
        //std::cout << j << std::endl;
    }
    int modulus = decomp_Num.size() % base;
    //std::cout << modulus << std::endl;
    switch(bases){
        case 10:
            //std::cout << num << std::endl;
            for(char a : num){
                //std::cout << a << std::endl;
                numstr.push_back(a);
            }
            for(int a = 0; a < static_cast<int>(numstr.size()); a++){
                int add = numstr[a] - '0';
                result += add * (static_cast<long long int>(pow(2, numstr.size() - a - 1)));
                //result += int(numstr[a]) * 2**(len(numstr) - a - 1)
            }
            finaleResult = std::to_string(result);
            break;
        case 2:
            finaleResult = num;
            break;
        case 8:
            for(int i = 0; i < base - modulus; i++){
                decomp_Num.insert(decomp_Num.begin(), "0");
            }
            /*
            for(std::string p : decomp_Num){
                std::cout << p << "  ";
            }
            */
            for(int j = 0 ; j < static_cast<int>(decomp_Num.size()) / base; j++){
                std::string temp_input = "";
                for(int i = 0 ; i < base; i++){
                    temp_input += decomp_Num[i + curr];
                }
                temp.emplace_back(temp_input);
                curr += base;
            }
            /*
            for(std::string tes : temp){
                std::cout << tes << "  ";
            }
            */
            for(std::string i :temp){
                tempFinale.emplace_back(dictionary8[i]);
            }
            finaleResult = FilteredDecompositionBasesofBinary(TemplateArray(ReverseArray(tempFinale)));
            break;
        case 16:
            for(int i = 0; i < base - modulus; i++){
                decomp_Num.insert(decomp_Num.begin(), "0");
            }
            /*
            for(std::string p : decomp_Num){
                std::cout << p << "  ";
            }
            */
            for(int j = 0 ; j < static_cast<int>(decomp_Num.size()) / base; j++){
                std::string temp_input = "";
                for(int i = 0 ; i < base; i++){
                    temp_input += decomp_Num[i + curr];
                }
                temp.emplace_back(temp_input);
                curr += base;
            }
            /*
            for(std::string tes : temp){
                std::cout << tes << "  ";
            }
            */
            for(std::string i :temp){
                tempFinale.emplace_back(dictionary8[i]);
            }
            finaleResult = FilteredDecompositionBasesofBinary(TemplateArray(ReverseArray(tempFinale)));
            break;
    }
    return finaleResult;
}

int IOstream(std::string num, std::string init){
    int init_bases = convertBases(init);
    switch(init_bases){
        case 2:
            std::cout << "binary = " << num << std::endl;
            std::cout << "octal = " << binary_to_bases(num, 8) << std::endl;
            std::cout << "decil = " << binary_to_bases(num, 10) << std::endl;
            std::cout << "hexa = " << binary_to_bases(num, 16) << std::endl;
        case 8:
            std::cout << "binary = " << bases_to_binary(num, 8) << std::endl;
            std::cout << "octal = " << num << std::endl;
            std::cout << "decil = " <<  binary_to_bases(bases_to_binary(num, 8), 10) << std::endl;
            std::cout << "hexa = " << binary_to_bases(bases_to_binary(num, 8), 16) << std::endl;
        case 10:
            std::cout << "binary = " << decil_to_bases(num, 2) << std::endl;
            std::cout << "octal = " << decil_to_bases(num, 8) << std::endl;
            std::cout << "decil = " << num << std::endl;
            std::cout << "hexa = " <<  decil_to_bases(num, 16) << std::endl;
        case 16:
            std::cout << "binary = " << bases_to_binary(num, 16) << std::endl;
            std::cout << "octal = " << binary_to_bases(bases_to_binary(num, 16), 8) << std::endl;
            std::cout << "decil = " << binary_to_bases(bases_to_binary(num, 16), 10) << std::endl;
            std::cout << "hexa = " << num << std::endl;
    }
    return 0;
}

int main(){
    bool loop = true;
    while(loop == true){
        std::string init;
        std::string end;
        std::string num;
        std::cout << "Enter the number type (binary/octal/decil/hexa): ";
        std::cin >> init;
        std::cout << "Enter the number want to process : ";
        std::cin >> num;
        IOstream(num, init);
    }
    return 0;
}