/*****************************************************************************/
/* Project name:    del - mathematics development language                   */
/* File Name:       del_interface_object_Object.cpp                          */
/* Description:     objects                                                  */
/* Copyright:       (c) 2006-2009 Dmitri Vlasov                              */
/* Author:          Dmitri Yurievich Vlasov, Novosibirsk, Russia             */
/* Email:           vlasov at academ.org                                     */
/* URL:             http://mathdevlanguage.sourceforge.net                   */
/* Modified by:                                                              */
/* License:         GNU General Public License Version 3                     */
/*****************************************************************************/

#pragma once

#include "del/interface/del_interface_Object.hpp"

namespace del {
namespace interface {

	/****************************
	 *		Public members
	 ****************************/

	void
	Object :: init()
	{
		if (string_ == NULL) {
			string_ = new String (INITAIL_STRING_CAPACITY);
		} else {
			string_->clear();
		}
	}
	void
	Object :: release()
	{
		nstd :: Object :: release();
		if (string_ != NULL) {
			delete string_;
			string_ = NULL;
		}
	}
	Size_t
	Object :: getStringVolume()
	{
		Size_t volume = 0;
		volume += getAggregateVolume (string_);
		volume += nstd :: Object :: getStringVolume();
		return volume;
	}

	void
	Object :: show (nstd :: String<>& string) const
	{
		if (string_ == NULL) {
			string_ = new String (INITAIL_STRING_CAPACITY);
		} else {
			string_->clear();
		}
		show (*string_);
		string << *string_;
	}

	/****************************
	 *		Operators
	 ****************************/

	String&
	operator << (String& string,  const Object& object)
	{
		object.show (string);
		return string;
	}
	std :: ostream&
	operator << (std :: ostream& os,  const Object& object)
	{
		if (Object :: string_ == NULL) {
			Object :: string_ = new String (Object :: INITAIL_STRING_CAPACITY);
		} else {
			Object :: string_->clear();
		}
		object.show (*(Object :: string_));
		os << *(Object :: string_);
		return os;
	}

	/*************************************
	 *		Private static attributes
	 *************************************/

	String* Object :: string_ = NULL;
}
}


