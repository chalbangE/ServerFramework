#pragma once
#include <iostream>
#include <array>
#include <WS2tcpip.h>
#include <MSWSock.h>
#include <thread>
#include <vector>
#include <mutex>
#include <algorithm>
#include <unordered_set>
#include <concurrent_priority_queue.h>

#pragma comment(lib, "WS2_32.lib")
#pragma comment(lib, "MSWSock.lib")
#include <windows.h>  
#include <sqlext.h>  

#include "ENUM.h"
#include "protocol.h"

#include "Vec3.h"

using namespace std;