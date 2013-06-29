#pragma once

#include "minko/Common.hpp"
#include "minko/Signal.hpp"

namespace
{
	using namespace minko::scene;
}

namespace minko
{
	namespace scene
	{
		namespace controller
		{
			class AbstractController
			{
				friend class minko::scene::Node;

			public:
				typedef std::shared_ptr<AbstractController>	Ptr;

			private:
				std::vector<std::shared_ptr<Node>>					_targets;

				std::shared_ptr<Signal<Ptr, std::shared_ptr<Node>>>	_targetAdded;
				std::shared_ptr<Signal<Ptr, std::shared_ptr<Node>>>	_targetRemoved;

			public:
				AbstractController() :
					_targetAdded(Signal<Ptr, std::shared_ptr<Node>>::create()),
					_targetRemoved(Signal<Ptr, std::shared_ptr<Node>>::create())
				{
				}

				virtual
				~AbstractController()
				{
				}

				inline
				const std::vector<std::shared_ptr<Node>>&
				targets()
				{
					return _targets;
				}

				inline
				Signal<Ptr, std::shared_ptr<Node>>::Ptr
				targetAdded()
				{
					return _targetAdded;
				}

				inline
				Signal<Ptr, std::shared_ptr<Node>>::Ptr
				targetRemoved()
				{
					return _targetRemoved;
				}
			};
		}
	}
}
