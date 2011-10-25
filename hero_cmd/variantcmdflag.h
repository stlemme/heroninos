
#pragma once
#ifndef __VARIANT_CMD_FLAG_H__
#define __VARIANT_CMD_FLAG_H__

#include "abstractcmdfragment.h"


class VariantCmdFlag : public AbstractCmdFragment
{
public:

    VariantCmdFlag();
    virtual ~VariantCmdFlag();

};

typedef QVector<VariantCmdFlag*> t_CmdFlags;

#endif // __VARIANT_CMD_FLAG_H__