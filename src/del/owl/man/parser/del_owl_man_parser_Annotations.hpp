/*****************************************************************************/
/* Project name:    del - mathematics development language                   */
/* File Name:       del_owl_man_parser_Annotations.hpp                       */
/* Description:     manchester OWL annotations parser                        */
/* Copyright:       (c) 2006-2009 Dmitri Vlasov                              */
/* Author:          Dmitri Yurievich Vlasov, Novosibirsk, Russia             */
/* Email:           vlasov at academ.org                                     */
/* URL:             http://mathdevlanguage.sourceforge.net                   */
/* Modified by:                                                              */
/* License:         GNU General Public License Version 3                     */
/*****************************************************************************/

#pragma once

#include "del/owl/man/lexer/del_owl_man_lexer.hpp"
#include "del/owl/man/parser/del_owl_man_parser.dpp"
#include "del/owl/man/source/del_owl_man_source.dpp"

namespace del {
namespace owl {
namespace man {
namespace parser {

class Annotations :
	public Object,
	public Scalar<Annotations> {
public :
	Annotations();
	virtual ~ Annotations();

	const source :: Annotations* parse (Lexer*);

	// object :: Object interface
	virtual void commitSuicide();
	virtual Size_t getVolume() const;
	virtual Size_t getSizeOf() const;
	virtual void show (String&) const;

private :
	// external part
	Location location_;
	source :: Annotations* annotations_;
	source :: Annotation* annotation_;

	// internal part
	String name_;
	String contents_;
	enum {
		INITIAL_NAME_CAPACITY = 32,
		INITIAL_CONTENTS_CAPACITY = 256
	};
};

}
}
}
}


