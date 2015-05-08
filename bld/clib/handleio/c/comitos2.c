/****************************************************************************
*
*                            Open Watcom Project
*
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  OS2 implementation of _commit().
*
****************************************************************************/


#include "variety.h"
#include <io.h>
#include <dos.h>
#include <wos2.h>
#include "rtdata.h"
#include "iomode.h"
#include "seterrno.h"

_WCRTLINK int _commit( int handle )
{
    unsigned    iomode_flags;
    APIRET      rc;

    iomode_flags = __GetIOMode( handle );
    if( iomode_flags == 0 ) {
        __set_errno( EBADF );
        return( 0 );
    }
    rc = DosBufReset( handle );
    if( rc ) {
        __set_errno_dos_reterr( rc );
        return( 0 );
    }
    return( -1 );
}
