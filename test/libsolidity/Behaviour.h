/*
	This file is part of solidity.
	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "Builtin.h"
#include <memory>
#include <vector>

namespace solidity::frontend::test
{

class TestFunctionCall;

class Behaviour
{
public:
	Behaviour() = default;
	virtual ~Behaviour() = default;

	virtual void begin() {}
	virtual void before([[maybe_unused]] TestFunctionCall const& _call) {}
	virtual void after([[maybe_unused]] TestFunctionCall const& _call) {}
	virtual void end() {}

	virtual bool isValid([[maybe_unused]] TestFunctionCall const& _call) { return true; }

	virtual std::string format(
		[[maybe_unused]] const TestFunctionCall& _call,
		[[maybe_unused]] ErrorReporter& _errorReporter,
		[[maybe_unused]] std::string const& _linePrefix,
		[[maybe_unused]] bool const _renderResult,
		[[maybe_unused]] bool const _highlight) const
	{
		return "";
	}
};

using Behaviours = std::vector<std::shared_ptr<Behaviour>>;

} // namespace solidity::frontend::test
