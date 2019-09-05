//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <OS.hpp>
#include <Collections/Generic/List.hpp>

namespace Alice
{
    namespace IO
    {
        class File
        {
        private:
            const char* filename = nullptr;

            #if defined(AliceWindows)
            const WCHAR* wfilename = nullptr;

            s32 filenamesize = 0;
            #endif
        public:
            AliceInline File() noexcept{}

            #if defined(AliceWindows)
            AliceInline File(const char* Filename) noexcept : filename(Filename), filenamesize(MultiByteToWideChar(CP_ACP, 0, Filename, -1, 0, 0))
            {
                wfilename = new WCHAR[filenamesize];
                MultiByteToWideChar(CP_ACP, 0, Filename, -1, (LPWSTR)wfilename, filenamesize);
            }

            AliceInline File(File&& Other) noexcept : filename(Other.filename), filenamesize(Other.filenamesize), wfilename(Other.wfilename)
            {
                Other.wfilename = nullptr;
                Other.filename = nullptr;
                Other.filenamesize = 0;
            }

            AliceInline ~File() noexcept
            {
                delete[] wfilename;
            }
            #endif

            AliceInline void operator=(const char* Filename) noexcept
            {
                if(Filename != nullptr)
                    filename = Filename;
                #if defined(AliceWindows)
                filenamesize = MultiByteToWideChar(CP_ACP, 0, Filename, -1, 0, 0);
                delete[] wfilename;
                wfilename = new WCHAR[filenamesize];
                MultiByteToWideChar(CP_ACP, 0, Filename, -1, (LPWSTR)wfilename, filenamesize);
                #endif
            }

            AliceInline void operator=(const char*&& Filename) noexcept
            {
                if(Filename != nullptr)
                    filename = Filename;
                #if defined(AliceWindows)
                filenamesize = MultiByteToWideChar(CP_ACP, 0, Filename, -1, 0, 0);
                delete[] wfilename;
                wfilename = new WCHAR[filenamesize];
                MultiByteToWideChar(CP_ACP, 0, Filename, -1, (LPWSTR)wfilename, filenamesize);
                #endif
            }

            //Exceptions: FileDoNotExists, FileIsAFolder
            AliceInline bool Exists() const noexcept
            {
                #if defined(AliceWindows)
                DWORD attrib = GetFileAttributesW(wfilename);
                if(attrib == INVALID_FILE_ATTRIBUTES)
                {
                    Exception::Raise(ExceptionType::FileDoNotExists);
                    return false;
                }
                else if((attrib & FILE_ATTRIBUTE_DIRECTORY))
                {
                    Exception::Raise(ExceptionType::FileIsAFolder);
                    return false;
                }
                return true;
                #endif
            }

            //Exceptions: FileDoNotExists, FileHandlerCouldNotBeCreated, FileSizeCouldNotBeExtracted
            AliceInline s64 Size() const noexcept
            {
                if(!Exists())
                {
                    Exception::Raise(ExceptionType::FileDoNotExists);
                    return 0;
                }
                else
                {
                    #if defined(AliceWindows)
                    HANDLE f = CreateFileW(wfilename, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
                    if(f == (HANDLE)(LONG_PTR)-1)
                    {
                        Exception::Raise(ExceptionType::FileHandlerCouldNotBeCreated);
                        return 0;
                    }
                    LARGE_INTEGER l;
                    if(!GetFileSizeEx(f, &l))
                    {
                        CloseHandle(f);
                        Exception::Raise(ExceptionType::FileSizeCouldNotBeExtracted);
                        return 0;
                    }
                    CloseHandle(f);
                    return l.QuadPart;
                    #endif
                }
            }

            //Exceptions: FileAlreadyExists, FileCouldNotBeCreated
            AliceInline void New() const noexcept
            {
                if(Exists())
                    Exception::Raise(ExceptionType::FileAlreadyExists);
                else
                {
                    #if defined(AliceWindows)
                    HANDLE f = CreateFileW(wfilename, 0, 0, 0, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0);
                    if(f == (HANDLE)(LONG_PTR)-1)
                        Exception::Raise(ExceptionType::FileCouldNotBeCreated);
                    else
                        CloseHandle(f);
                    #endif
                }
            }

            //Exceptions: FileDoNotExists, FileCouldNotBeDeleted
            AliceInline void Delete() const noexcept
            {
                if(!Exists())
                    Exception::Raise(ExceptionType::FileDoNotExists);
                else
                {
                    #if defined(AliceWindows)
                    if(DeleteFileW(wfilename) == 0)
                        Exception::Raise(ExceptionType::FileCouldNotBeDeleted);
                    #endif
                }
            }

            //Exceptions: FileDoNotExists, FileHandlerCouldNotBeCreated, FileCouldNotBeReaded
            AliceInline void Read(Collections::Generic::List<char>& Buffer) const noexcept
            {
                if(!Exists())
                    Exception::Raise(ExceptionType::FileDoNotExists);
                else
                {
                    #if defined(AliceWindows)
                    HANDLE f = CreateFileW(wfilename, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
                    if(f == (HANDLE)(LONG_PTR)-1)
                        Exception::Raise(ExceptionType::FileHandlerCouldNotBeCreated);
                    else
                    {
                        OVERLAPPED o = {0};
                        if(FALSE == ReadFileEx(f, &Buffer[0], Buffer.Capacity(), &o, 0))
                        {
                            CloseHandle(f);
                            Exception::Raise(ExceptionType::FileCouldNotBeReaded);
                        }
                        else
                            CloseHandle(f);
                    }
                    #endif
                }
            }

            //Exceptions: FileDoNotExists, FileHandlerCouldNotBeCreated, FileCouldNotBeWritten
            AliceInline void Write(Collections::Generic::List<char>&& Buffer) const noexcept
            {
                if(!Exists())
                    Exception::Raise(ExceptionType::FileDoNotExists);
                else
                {
                    #if defined(AliceWindows)
                    HANDLE f = CreateFileW(wfilename, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
                    if(f == (HANDLE)(LONG_PTR)-1)
                        Exception::Raise(ExceptionType::FileHandlerCouldNotBeCreated);
                    else
                    {
                        OVERLAPPED o = {0};
                        if(FALSE == WriteFileEx(f, &Buffer[0], Buffer.Capacity(), &o, 0))
                        {
                            CloseHandle(f);
                            Exception::Raise(ExceptionType::FileCouldNotBeWritten);
                        }
                        else
                            CloseHandle(f);
                    }
                    #endif
                }
            }

            //Exceptions: FileDoNotExists, FileHandlerCouldNotBeCreated, FileCouldNotBeWritten
            AliceInline void Write(const char* Buffer) const noexcept
            {
                if(!Exists())
                    Exception::Raise(ExceptionType::FileDoNotExists);
                else
                {
                    #if defined(AliceWindows)
                    HANDLE f = CreateFileW(wfilename, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
                    if(f == (HANDLE)(LONG_PTR)-1)
                        Exception::Raise(ExceptionType::FileHandlerCouldNotBeCreated);
                    else
                    {
                        OVERLAPPED o = {0};
                        if(FALSE == WriteFileEx(f, &Buffer[0], MultiByteToWideChar(CP_ACP, 0, Buffer, -1, 0, 0), &o, 0))
                        {
                            CloseHandle(f);
                            Exception::Raise(ExceptionType::FileCouldNotBeWritten);
                        }
                        else
                            CloseHandle(f);
                    }
                    #endif
                }
            }
        };
    }
}