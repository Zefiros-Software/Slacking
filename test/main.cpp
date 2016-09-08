#include "slacking/slacking.hpp"

#include <fstream>

void more_elaborate_example()
{
    auto &slack = slack::instance();
    slack.chat.channel_username_iconemoji( "#mychannel", "Support Bot", ":hamster:" );

    auto json_attachments = R"([
        {
            "fallback": "New ticket from Bjarne Stroustrup - Ticket #2017: Still looking for reflection",
            "pretext": "New ticket from Bjarne Stroustrup",
            "title": "Ticket #2017: Still looking for reflection",
            "title_link": "https://www.youtube.com/watch?v=ND-TuW0KIgg",
            "text": "Help me adding reflection!",
            "color": "#7CD197",
            "image_url": "https://img.youtube.com/vi/ND-TuW0KIgg/2.jpg"
        }
    ])"_json;

    slack.chat.attachments =
        json_attachments; // equivalent to slack::instance().chat_postMessage.attachments = json_attachments.dump();
    auto result = slack.chat.postMessage();

    std::cout << result << std::endl;
}


int main()
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

    {
        more_elaborate_example();
    }
}