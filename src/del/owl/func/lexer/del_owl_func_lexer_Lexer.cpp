/*****************************************************************************/
/* Project name:    del - mathematics development language                   */
/* File Name:       del_owl_func_lexer_Lexer.cpp                             */
/* Description:     functional OWL2 lexer class                              */
/* Copyright:       (c) 2006-2009 Dmitri Vlasov                              */
/* Author:          Dmitri Yurievich Vlasov, Novosibirsk, Russia             */
/* Email:           vlasov at academ.org                                     */
/* URL:             http://mathdevlanguage.sourceforge.net                   */
/* Modified by:                                                              */
/* License:         GNU General Public License Version 3                     */
/*****************************************************************************/

#pragma once

#include "del/owl/func/lexer/del_owl_func_lexer.hpp"

namespace del {
namespace owl {
namespace func {
namespace lexer {

	/****************************
	 *		Public members
	 ****************************/

	// object :: Object implementation
	void
	Lexer :: commitSuicide() {
		delete this;
	}
	Size_t
	Lexer :: getVolume() const
	{
		Size_t volume = 0;
		volume += source_.getVolume();
		volume += scaner_.getVolume();
		volume += token_.getVolume();
		return volume;
	}
	Size_t
	Lexer :: getSizeOf() const {
		return sizeof (Lexer);
	}
	void
	Lexer :: show (String&) const {
	}

	/************************************
	 *		Static private attributes
	 ************************************/
}
}
}
}


