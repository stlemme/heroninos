
#pragma once
#ifndef __STABLE_H__
#define __STABLE_H__

#ifdef WIN32
    #define WINDOWS_LEAN_AND_MEAN
#endif // WIN32

#include "pragmanote.h"


// STABLE DEFINES

#define APPLICATION_NAME     "Heroninos"
#define APPLICATION_VERSION  "0.0.0"
#define APPLICATION_AUTHOR   "Daniel Müller"


// STABLE INCLUDES

#include <assert.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795

#define RAD2DEG 180.0 / PI
#define DEG2RAD PI / 180.0

#include <QHash>
#include <QSet>
#include <QList>
#include <QMap>
#include <QQueue>
#include <QVector>


#define TR QObject::tr

#endif // __STABLE_H__