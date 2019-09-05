#include <Core/AppContext.hpp>

//The PID of the executing app
u32 foo()
{
    return Alice::AppContext::GetApplicationID();
}








//If our executing app would be at location D:\Example\Program1.exe


//This would show the full executing app location, so it would be equal to D:\Example\Program1.exe
const char* ExecutingApp = ExecutableDirectory;

//This would show the base of the full executing app location, so it would be equal to D:\Example\

const char* BaseDir = BaseDirectory;