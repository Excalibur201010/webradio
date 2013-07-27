/*
 * WebRadio web-based Software Defined Radio
 *
 * Copyright (C) 2013 Mike Stirling
 *
 * This file is part of WebRadio (http://www.mike-stirling.com/webradio)
 *
 * All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TUNERCONTROLHANDLER_H_
#define TUNERCONTROLHANDLER_H_

#include <vector>
#include <string>
#include <json/json.h>

#include "httpserver.h"
#include "radio.h"

class TunerControlHandler : public HttpRequestHandler
{
public:
	TunerControlHandler();
	~TunerControlHandler();
	static HttpRequestHandler *factory() {
		return new TunerControlHandler();
	}

	const string allows(const vector<string> &wildcards) { return "GET, PUT"; }

	unsigned short doGet(const vector<string> &wildcards, const vector<char> &requestData);
	unsigned short doPut(const vector<string> &wildcards, const vector<char> &requestData);
private:
	Json::Value buildTunerControl(FrontEnd *fe);
	unsigned short parseTunerControl(FrontEnd *fe, Json::Value &root);
};

#endif /* TUNERCONTROLHANDLER_H_ */
