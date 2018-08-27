//===----------------------------------------------------------------------===//
//
//                         DuckDB
//
// parser/statement/create_statement.hpp
//
// Author: Hannes Mühleisen & Mark Raasveldt
//
//===----------------------------------------------------------------------===//

#pragma once

#include <vector>

#include "catalog/catalog.hpp"
#include "parser/statement/sql_statement.hpp"

#include "parser/expression/abstract_expression.hpp"

namespace duckdb {

class ExplainStatement : public SQLStatement {
  public:
	ExplainStatement(std::unique_ptr<SQLStatement> stmt)
	    : SQLStatement(StatementType::EXPLAIN), stmt(move(stmt)){};
	std::unique_ptr<SQLStatement> stmt;

	virtual ~ExplainStatement() {}

	virtual std::string ToString() const { return "Explain"; }
	virtual void Accept(SQLNodeVisitor *v) { }
};

} // namespace duckdb
