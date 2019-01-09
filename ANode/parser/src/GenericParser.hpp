#ifndef GENERIC_PARSER_HPP_
#define  GENERIC_PARSER_HPP_
/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// Name        :
// Author      : Avi
// Revision    : $Revision: #6 $
//
// Copyright 2009-2017 ECMWF.
// This software is licensed under the terms of the Apache Licence version 2.0
// which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
// In applying this licence, ECMWF does not waive the privileges and immunities
// granted to it by virtue of its status as an intergovernmental organisation
// nor does it submit to any jurisdiction.
/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8

#include "Parser.hpp"

class GenericParser : public Parser {
public:
   GenericParser(DefsStructureParser* p) : Parser(p) {}
   const char* keyword() const override { return "generic"; }
   bool doParse( const std::string& line, std::vector<std::string >& lineTokens ) override;
};

#endif