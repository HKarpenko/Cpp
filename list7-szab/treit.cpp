#include <iostream>
#include <cstring>

#include "treit.hpp"


bool first_type_traits<const char*>::compare(const char* lt,const char* rt){
    int it=0;
    while(lt[it]!='\0' && rt[it]!='\0'){
        if(lt[it]>rt[it])
            return true;
        else if(lt[it]<rt[it])
            return false;
        it++;
    }
    if(lt[it]=='\0')
        return false;
    return true;
}

bool second_type_traits<const char*>::compare(const char* lt,const char* rt){
    int it=0;
    while(lt[it]!='\0' && rt[it]!='\0'){
        if(lt[it]<rt[it])
            return true;
        else if(lt[it]>rt[it])
            return false;
        it++;
    }
    if(rt[it]=='\0')
        return false;
    return true;
}
