/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016-2018 Zefiros Software.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @endcond
 */
#define INSECURE_CURL
#include "slacking/slacking.hpp"

#include <fstream>

int main()
{
    try
    {
        auto &slack = slack::create( "xxx-xxx" ); // where "xxx-xxx" is your Slack API token
        slack.chat.channel = "#general";
        slack.chat.postMessage( "Hello there!" ); // will send the message "Hello there!" in the channel #general

        {
            // You can also use the generic post slack approach. Parameters (except the token) will not be taken into account.
            // Everything from the Web Slack API is possible here!
            slack::post(
                "chat.postMessage",
            {
                {"text"      , "Slacking is awesome!" },
                {"channel"   , "#general"             },
                {"username"  , "peach"                },
                {"icon_emoji", ":princess:"           }
            }
            );
        }

        {
            // You can also use the generic post with a a Json approach.
            auto json = R"({
            "text": "Slacking is awesome!",
            "channel" : "#general",
            "username": "peach",
            "icon_emoji": ":princess:"
        })"_json;

            slack::post( "chat.postMessage", json );
        }
    }
    catch ( const std::runtime_error &e )
    {
        if ( std::string( e.what() ) != "\"invalid_auth\"" )
        {
            throw e;
        }
    }

    return 0;
}