/*****************************************************************************/
/* Project name:    del - mathematics development language                   */
/* File Name:       del_model_node_negative_Simple.cpp                       */
/* Description:     a negative node container of type: simple                */
/* Copyright:       (c) 2006-2009 Dmitri Vlasov                              */
/* Author:          Dmitri Yurievich Vlasov, Novosibirsk, Russia             */
/* Email:           vlasov at academ.org                                     */
/* URL:             http://mathdevlanguage.sourceforge.net                   */
/* Modified by:                                                              */
/* License:         GNU General Public License Version 3                     */
/*****************************************************************************/

#pragma once

#include "del/interface/del_interface.hpp"

namespace del {
namespace model {
namespace node {
namespace negative {

	/****************************
	 *		Public members
	 ****************************/

	template<class A>
	inline
	Simple<A> :: Simple (Model* model) :
	Negative_ (model)
	{
		if (model != NULL) {
			model->registerNode (this);
		}
	}
	template<class A>
	inline
	Simple<A> :: Simple
	(
		Model* model,
		const Formula* formula,
		const value :: Integer size
	) :
	Negative_ (model, formula, size)
	{
		if (model != NULL) {
			model->registerNode (this);
		}
	}
	template<class A>
	inline
	Simple<A> :: Simple
	(
		Model* model,
		const Node* node,
		const Formula* formula
	) :
	Negative_ (model, node, formula)
	{
		if (model != NULL) {
			model->registerNode (this);
		}
	}
	template<class A>
	inline
	Simple<A> :: Simple
	(
		Model* model,
		const Node* nodes[],
		const value :: Integer size,
		const Formula* formula
	) :
	Negative_ (model, nodes, size, formula)
	{
		if (model != NULL) {
			model->registerNode (this);
		}
	}
	template<class A>
	template<class A1>
	Simple<A> :: Simple (const Simple<A1>& node, Model* model) :
	Negative_ (node, model)
	{
		if (model != NULL) {
			model->registerNode (this);
		}
	}
	template<class A>
	Simple<A> :: ~ Simple () {
	}

	// del :: Node implementation
	template<class A>
	const Term*
	Simple<A> :: evalInterpolant (const Signature* delta) const
	{
		if (Node :: isVisited()) {
			return Node :: getInterpolant();
		}
		Node :: setInterpolant (NULL);
		Node :: setVisited();

		// let formula be:   a ⊑ b
		const Term* term_0 = Negative_ :: formula_->getTerm (0);
		const Term* term_1 = Negative_ :: formula_->getTerm (1);
		const Term* interpolant = NULL;
		if (term_0->isOfSignature (delta)) {
			interpolant = term_0->clone();
		} else if (term_1->isOfSignature (delta)) {
			interpolant = term_1->clone();
		} else {
			const Node* node = Negative_ :: nodeVector_.getFirstValue();
			interpolant = node->evalInterpolant (delta);
			if (interpolant != NULL) {
				interpolant = interpolant->clone();
			}
		}
		Node :: setInterpolant (interpolant);
		return interpolant;
	}
	template<class A>
	model :: Node*
	Simple<A> :: clone (model :: Model* model) const
	{
		if (Node :: clone_ == NULL) {
			Node :: clone_ = new Simple
			(
				model,
				Negative_ :: formula_,
				Negative_ :: nodeVector_.getSize()
			);
			Negative_ :: cloneNodeVector (model);
		}
		return Node :: clone_;
	}
	template<class A>
	bool
	Simple<A> :: isEqual (const Node* node, const bool show) const
	{
		if (!Node :: isVisited()) {
			Node :: setTrue();
			Node :: setVisited();
			if (Negative_ :: isEqual (node, show)) {
				const Simple* simple = dynamic_cast<const Simple*>(node);
				if (simple == NULL) {
					if (show) {
						std :: cout << "Inequality in <node :: negative :: Simple> class." << std :: endl;
						std :: cout << "------------------------------------------------------" << std :: endl;
						std :: cout << "Node: " << (void*)node << "does not cast to <Simple>" << std :: endl;
						std :: cout << " -- node 1 = " << *this << std :: endl;
						std :: cout << " -- node 2 = " << *node << std :: endl;
					}
					Node :: setFalse();
				}
			}
		}
		return Node :: isTrue();
	}

	// del :: Object implementation
	template<class A>
	void
	Simple<A> :: commitSuicide() {
		delete this;
	}
	template<class A>
	Size_t
	Simple<A> :: getSizeOf() const {
		return sizeof (Simple);
	}
	template<class A>
	Size_t
	Simple<A> :: getVolume() const {
		return Negative_ :: getVolume();
	}
	template<class A>
	void
	Simple<A> :: show (String& string) const
	{
		string << "simple ";
		Negative_ :: show (string);
	}
}
}
}
}


