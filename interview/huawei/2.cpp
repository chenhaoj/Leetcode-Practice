#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> matchFiles(const std::string& rule, const std::vector<std::string>& fileList) {
    std::vector<std::string> matches;
    std::vector<std::string> directories;
    
    for (const std::string& line : fileList) {
        std::string indent, filePath;
        std::size_t pos = line.find_first_not_of(" ");
        
        if (pos != std::string::npos) {
            indent = line.substr(0, pos);
            filePath = line.substr(pos);
        }

        // 计算文件或目录名称的缩进级别
        int level = indent.size() / 4;

        // 构建完整路径
        std::string fullPath;
        for(int i = 0; i <= level; ++i) {
            
        }

        // 判断是否与规则匹配
        if (std::regex_match(filePath, std::regex(rule))) {
            // 构建完整的文件路径
            std::string fullPath;
            for (int i = 0; i <= level; ++i) {
                if (i < static_cast<int>(directories.size())) {
                    fullPath += directories[i] + "/";
                }
                else {
                    break;
                }
            }
            fullPath += filePath;
            matches.push_back(fullPath);
        }
        
        if (level < static_cast<int>(directories.size())) {
            directories.resize(level + 1);
            directories[level] = filePath;
        }
        else {
            directories.push_back(filePath);
        }
    }
    
    if (matches.empty()) {
        matches.push_back("NOT FOUND");
    }
    
    return matches;
}

int main() {
    std::string rule;
    std::getline(std::cin, rule);
    // std::cout << rule << std::endl;
    std::vector<std::string> fileList;
    std::string line;
    std::getline(std::cin, line);
    while (line != "") {
        fileList.push_back(line);
        std::getline(std::cin, line);
    }
    // for(int i = 0; i < fileList.size(); i++) {
    //     std::cout << fileList[i] << std::endl;
    // }
    std::vector<std::string> results = matchFiles(rule, fileList);
    for (const std::string& result : results) {
        std::cout << result << std::endl;
    }
    
    return 0;
}