# cfgps

a parser for config file

目前用作平时网络课作业，用于解析配置文件。

## 接口约定


void Parser.set(const char \*section, const char \*key, const char \*value, bool (*check_func)(const char*) = nullptr);
void Parser.set(const char \*section, const char \*key, int value, bool (*check_func)(int) = nullptr);

void Parser.read_file(const char \*file_path);

int Parser.get_int(const char \*section, const char \*key);
const char* Parser.get_str(const char \*section, const char \*key);

暂定。
