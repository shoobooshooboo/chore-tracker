# Sprint x Report 
Video Link: https://www.youtube.com/watch?v=ujife3r0kf4
## What's New (User Facing)
### Front end:
* information displays
* dynamic UI element updates
* displaying arbitrary amounts of info
### Back end:
* encryption of user data
* creating, removing chores in a household
* retrieving filtered/sorted views of chores from household data

## Work Summary (Developer Facing)
### Front end:
Front end worked on gathering the tools necessary to make a functioning interface. Most of their work has been researching Qt Creator so that when backend is functional, it can easily be integrated.
### Back end:
Back end worked on constructing the main structure of the underlying logic of the program. We can't have a chore tracking app without being able to store chores, users, and households in an efficient way, so we need that built before we can even really prototype an accurate front end.

## Unfinished Work
IA couple back end items were started but not finished. This was due to them being lower priority and the back end team running out of time during the sprint.

## Completed Issues/User Stories
Here are links to the issues that we completed in this sprint: 
__***NOTE: *** None of these issues are linked to pull requests yet because back end and front end are not ready for integration yet.__

 * [Information displays](https://github.com/shoobooshooboo/chore-tracker/issues/4)
 * [dynamic UI element updates](https://github.com/shoobooshooboo/chore-tracker/issues/6)
 * [Creating, Removing chores in a household](https://github.com/shoobooshooboo/chore-tracker/issues/11)
 * [Displaying arbitrary amounts of info](https://github.com/shoobooshooboo/chore-tracker/issues/13)
 * [encryption](https://github.com/shoobooshooboo/chore-tracker/issues/14)
 * [retrieving filtered/sorted views of chores from household data](https://github.com/shoobooshooboo/chore-tracker/issues/15)
 
 ## Incomplete Issues/User Stories
 Here are links to issues we worked on but did not complete in this sprint:
 
 * [login/sign up backend handling/passing to startup process](https://github.com/shoobooshooboo/chore-tracker/issues/12) <<Ran out of time. Prioritized other issues.>>
 * [Loading from and storing users to file](https://github.com/shoobooshooboo/chore-tracker/issues/7) <<Ran out of time. Mostly implemented.>>
 * [Loading from and storing households to file](https://github.com/shoobooshooboo/chore-tracker/issues/8) <<Ran out of time. Mostly implemented.>>

## Code Files for Review
Please review the following code files, which were actively developed during this sprint, for quality:
 * [chore.cpp](https://github.com/shoobooshooboo/chore-tracker/tree/dev-backend/chore.cpp)
 * [chore.hpp](https://github.com/shoobooshooboo/chore-tracker/tree/dev-backend/chore.hpp)
 * [encryption.cpp](https://github.com/shoobooshooboo/chore-tracker/tree/dev-backend/encryption.cpp)
 * [encryption.hpp](https://github.com/shoobooshooboo/chore-tracker/tree/dev-backend/encryption.hpp)
 * [household.cpp](https://github.com/shoobooshooboo/chore-tracker/tree/dev-backend/household.cpp)
 * [household.hpp](https://github.com/shoobooshooboo/chore-tracker/tree/dev-backend/household.hpp)
 * [household_manager.cpp](https://github.com/shoobooshooboo/chore-tracker/tree/dev-backend/household_manager.cpp)
 * [household_manager.hpp](https://github.com/shoobooshooboo/chore-tracker/tree/dev-backend/household_manager.hpp)
 * [user.cpp](https://github.com/shoobooshooboo/chore-tracker/tree/dev-backend/user.cpp)
 * [user.hpp](https://github.com/shoobooshooboo/chore-tracker/tree/dev-backend/user.hpp)
 * [user_manager.cpp](https://github.com/shoobooshooboo/chore-tracker/tree/dev-backend/user_manager.cpp)
 * [user_manager.hpp](https://github.com/shoobooshooboo/chore-tracker/tree/dev-backend/user_manager.hpp)
 
## Retrospective Summary
Here's what went well:
  * Communication
  * Planning
  * Understanding of objectives
 
Here's what we'd like to improve:
  * Number of items worked on
  * Realistic expectations for the amount of time it takes to research
  
Here are changes we plan to implement in the next sprint:
  * Finish basic front end issues
  * Get back end to an integrateable point
  * Integrate front end and back end
  * GUI for editing chores