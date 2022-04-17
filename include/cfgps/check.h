#pragma once
#ifndef CFGPS_CHECK_H
#define CFGPS_CHECK_H

#include <cfgps/cfgps.h>
#include <cstring>
namespace cfgps {
bool _checkStrVerify(cfgps::Value val);
bool _checkStrVerify_Y(cfgps::Value val);
bool _checkStrVerify_N(cfgps::Value val);

bool _checkStrIpaddr(cfgps::Value val);
} // namespace cfgps

#ifndef CHECK_INT_BETWEEN
#define CHECK_INT_BETWEEN(left, right)                                         \
	[](cfgps::Value val) { return val.Int >= left && val.Int <= right; }
#endif

#ifndef CHECK_STR_IN
#define CHECK_STR_IN(...)                                                      \
	[](cfgps::Value val) {                                                      \
		if (!val.Str)                                                          \
			return false;                                                      \
		const char *_str_list[] = {__VA_ARGS__, NULL};                         \
		for (int i = 0; _str_list[i]; i++) {                                   \
			if (!strcmp(val.Str, _str_list[i]))                                \
				return true;                                                   \
		}                                                                      \
		return false;                                                          \
	}
#endif

#ifndef CHECK_STR_VERIFY
#define CHECK_STR_VERIFY cfgps::_checkStrVerify
#endif

#ifndef CHECK_STR_VERIFY_Y
#define CHECK_STR_VERIFY_Y cfgps::_checkStrVerify_Y
#endif

#ifndef CHECK_STR_VERIFY_N
#define CHECK_STR_VERIFY_N cfgps::_checkStrVerify_N
#endif

#ifndef CHECK_STR_IPADDR
#define CHECK_STR_IPADDR cfgps::_checkStrIpaddr
#endif

#endif
