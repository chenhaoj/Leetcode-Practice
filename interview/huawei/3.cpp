#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> matchFiles(const std::string& rule, const std::vector<std::string>& fileList) {
    std::vector<std::string> matches;
    
    // 将规则中的 "*" 转换为正则表达式中的通配符形式 ".*"
    std::string regexRule = std::regex_replace(rule, std::regex("\\*"), ".*");
    
    for (const std::string& line : fileList) {
        std::string indent, filePath;
        std::size_t pos = line.find_first_not_of(" ");
        
        if (pos != std::string::npos) {
            indent = line.substr(0, pos);
            filePath = line.substr(pos);
        }
        
        // 计算文件或目录名称的缩进级别
        int level = indent.size() / 4;
        
        // 构建完整的文件路径
        std::string fullPath;
        for (int i = 0; i < level; ++i) {
            fullPath += matches[i] + "/";
        }
        fullPath += filePath;
        
        // 判断是否与规则匹配
        if (std::regex_match(fullPath, std::regex(regexRule))) {
            matches.resize(level + 1);
            matches[level] = filePath;
            std::cout << fullPath << std::endl;
        }
    }
    
    if (matches.empty()) {
        std::cout << "NOT FOUND" << std::endl;
    }
    
    return matches;
}

int main() {
    std::string rule;
    std::getline(std::cin, rule);
    
    std::vector<std::string> fileList;
    std::string line;
    std::getline(std::cin, line);
    while (line != "") {
        fileList.push_back(line);
        std::getline(std::cin, line);
    }
    
    std::vector<std::string> results = matchFiles(rule, fileList);
    for (const std::string& result : results) {
        std::cout << result << std::endl;
    }
    
    return 0;
}
