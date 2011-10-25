
#include "cmd_make.h"

#include "arg_filepath.h"
#include "arg_passphrase.h"


CmdMake::CmdMake()
:   AbstractCmd()
{
    arg_filePath = new ArgFilePath(true);
    arg_passphrase = new ArgPassphrase();

    this->operator<<(arg_filePath);
    this->operator<<(arg_passphrase);
    

    //f_encrypted = FlagCmd("encrypted");
    //f_encrypted << new ArgString("passphrase");

    //this << a_filePath;
    //this << f_encrypted;
}


CmdMake::~CmdMake()
{
    delete arg_filePath;
    delete arg_passphrase;
}


const QString CmdMake::command() const
{
    return "make";
}


const QString CmdMake::comment() const
{
    return "todo";
}


const QFileInfo &CmdMake::filePath() const
{
    return arg_filePath->fileInfo();
}


const QString &CmdMake::passphrase() const
{
    return arg_passphrase->passphrase();
}