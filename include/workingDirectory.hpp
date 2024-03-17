#ifndef WORKING_DIR_HPP
#define WORKING_DIR_HPP

#include <string>

class WorkingDirectory
{
    public:
        WorkingDirectory();    
        inline const std::string& get() { return path; }
    
    private:
        std::string path;
};

#endif