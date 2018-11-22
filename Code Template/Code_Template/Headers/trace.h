/**
 * CodeObsess (SpawnTree)
 * Copyright © 2018 CodeObsess All rights reserved
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string>

#ifndef trace_h
#define trace_h

#define CM_TRACE_FILE(trace_file)    cm::Trace::LogToFile(trace_file)

#define CM_TRACE_FUNC(func_name)    cm::Trace __CM_TRACE__(func_name, "()")
#define CM_TRACE_FUNC_ARG1(func_name, argfmt, arg)   \
cm::Trace __CM_TRACE__(func_name, argfmt, arg)
#define CM_TRACE_FUNC_ARG2(func_name, argfmt, arg1, arg2)   \
cm::Trace __CM_TRACE__(func_name, argfmt, arg1, arg2)

namespace    cm
{
    class    Trace
    {
    public:
        explicit Trace(char *func_name, const char* argsfmt, ...)
        {
            char fmt[256] ={0};
            sprintf(fmt, "%s%s", func_name, argsfmt);
            va_list arglist;
            va_start(arglist, argsfmt);
            LogMsg(depth_, depth_ * 2, fmt,  arglist);
            va_end(arglist);
            ++depth_;
        }
        
        ~Trace()
        {
            --depth_;
        }
        
        /// special the global log file.
        void static LogToFile(const char *trace_file)
        {
            trace_file_ = trace_file;
        }
        
    private:
        void LogMsg(int depth, int align, const char *fmt, va_list args)
        {
            FILE    *fp = fopen(trace_file_.c_str(), "a+");
            if (fp == NULL)
            {
                return;
            }
            
            
            time_t        curTime;
            time(&curTime);
            
            char    timeStamp[32] = { 0 };
            strftime(timeStamp, sizeof(timeStamp),
                     "%Y%m%d.%H%M%S", localtime(&curTime));
            
            // only log the timestamp when the time changes
            unsigned int len = fprintf( fp, "%s %*.*s> (%d)",
                                       (last_invoke_time_ != curTime) ?
                                       timeStamp : "               ",
                                       2 * depth,
                                       2 * depth,
                                       nest_,
                                       depth);
            last_invoke_time_ = curTime;
            len += vfprintf(fp, fmt, args);
            len += fwrite("\n", 1, 1, fp);
            fflush(fp);
            fclose(fp);
        }
        
    private:
        // the debug trace filename
        static std::string    trace_file_;
        
        // function call stack depth
        static int            depth_;
        static const char*  nest_;
        static time_t       last_invoke_time_;
    };
    
    std::string Trace::trace_file_  = "";
    int         Trace::depth_       = 0;
    
    // arbitrarily support nesting 34 deep for no particular reason
    const char* Trace::nest_        =
    "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | ";
    time_t      Trace::last_invoke_time_ = 0;
}    // end namespace cm
#endif
