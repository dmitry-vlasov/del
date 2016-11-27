/*****************************************************************************/
/* Project name:    nstd - non-standard library                              */
/* File name:       nstd_memory_exception_EmptyStackPop.hpp                  */
/* Description:     exception at empty stack pop attempt                     */
/* Copyright:       (c) 2006-2009 Dmitri Vlasov                              */
/* Author:          Dmitri Yurievich Vlasov, Novosibirsk, Russia             */
/* Email:           vlasov at academ.org                                     */
/* URL:             http://mathdevlanguage.sourceforge.net                   */
/* Modified by:                                                              */
/* License:         GNU General Public License Version 3                     */
/*****************************************************************************/

#pragma once

#include "memory/exception/nstd_memory_exception_Exception.hpp"

namespace nstd {
namespace memory {
namespace exception {

class EmptyStackPop : public Exception {
public :
	EmptyStackPop() throw();
	EmptyStackPop (const EmptyStackPop&) throw();
	virtual ~ EmptyStackPop() throw();
};

}
}
}


