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