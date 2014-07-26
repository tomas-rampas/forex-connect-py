#include "stdafx.h"
#include <IO2GSession.h>
using namespace boost::python;

class IO2GSessionDescriptorWrap : public IO2GSessionDescriptor, public wrapper < IO2GSessionDescriptor >
{
public:
};

class IO2GSessionDescriptorCollectionWrap : public IO2GSessionDescriptorCollection, public wrapper < IO2GSessionDescriptorCollection >
{
public:
};

class IO2GSessionStatusWrap : public IO2GSessionStatus, public wrapper < IO2GSessionStatus >
{
public:
};

class IO2GTableManagerListenerWrap : public IO2GTableManagerListener, public wrapper < IO2GTableManagerListener >
{
public:
};

class IO2GSessionWrap : public IO2GSession, public wrapper < IO2GSession >
{
public:
};

void export_IO2GSession()
{

};