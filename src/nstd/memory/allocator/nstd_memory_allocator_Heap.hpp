/*****************************************************************************/
/* Project name:    nstd - non-standard library                              */
/* File name:       nstd_memory_allocator_Heap.hpp                           */
/* Description:     heap allocator                                           */
/* Copyright:       (c) 2006-2009 Dmitri Vlasov                              */
/* Author:          Dmitri Yurievich Vlasov, Novosibirsk, Russia             */
/* Email:           vlasov at academ.org                                     */
/* URL:             http://mathdevlanguage.sourceforge.net                   */
/* Modified by:                                                              */
/* License:         GNU General Public License Version 3                     */
/*****************************************************************************/

#pragma once

namespace nstd {
namespace memory {
namespace allocator {

class Heap {
public :
	template<class T>
	static const Interval<T> allocateScalar (const Size_t);
	template<class T>
	static const Interval<T> allocateVector (const Size_t, const Method = DEFAULT);
	template<class T>
	static void dispose (const Interval<T>&);
	static void setControl (const void*, const Size_t);

private :
	static pthread_mutex_t mutex_;
	static Control control_;
};

}
}
}


