
#pragma once
#ifndef __CMD_MAKE_H__
#define __CMD_MAKE_H__

#include "abstractcmd.h"

class ArgFilePath;
class ArgPassphrase;

class QFileInfo;


class CmdMake : public AbstractCmd
{
public:

    CmdMake();
    virtual ~CmdMake();

    virtual const QString command() const;
    virtual const QString comment() const;

    const QFileInfo &filePath() const;
    const QString &passphrase() const;

protected:
    ArgFilePath *arg_filePath;
    ArgPassphrase *arg_passphrase;
};

#endif // __CMD_MAKE_H__