# Sprint x Report
Video Link: https://www.youtube.com/watch?v=hrjCXNl_YBc

## What's New (User Facing)
* Information receptacles
* Buttons that go into a menu
* Back buttons
* Reading and Writing Household to and from files
* Reading and Writing Users to and from files

## Work Summary (Developer Facing)
With frontend, we began implementing a function which essentially preserves the state of the program into the text file. By using an “on-text-changed” detection, we were able to implement a function that saves the text that the user inputs into the text box. The function goes into effect at every instance where the text is changed. This will become a key feature within the program because we will need to save and store tasks and user profiles when the application is not being run. It also initiates the connection with the user and the program in the form of text. With the user being able to interact with the program through a text box, it allows the user to create and modify their own data within the database. In this case, the data corresponds to tasks and user profiles. On the backend side, we discussed overall functionality and the rest of the project. For specific issues, we created functionality to write all the data from a user into a file. This included adding extra functionality for the user to store data we did not previously think was required, along with ways to access this data. We also created the functionality to write all the data from a household to a file. For this, we needed to add more data members to the household to be able to fully encapsulate the different parts of a household, similarly to how we had to edit the users. 

## Unfinished Work
The main purpose of this sprint was to integrate front-end and back-end, but while we did finish the preparations, we were not able to do the actual integration. This is for a multitude of reasons, but essentially boils down to this: a lack of motivation. At the beginning of the semester, we were actually very motivated and even excited to work on this project, but that excitement slowly dwindled down and has all but completely faded now. One of the problems is just that we’re all very busy with our other classes. We have a weekly group meeting and it’s rare for us to be able to spend the whole time talking about only this class. Another big issue with the class is how much busy work there is. It feels like every week, we’re given pointless assignments that don’t engage us or improve our understanding of what they’re trying to teach and that kills our motivation for not just everything in this class, but our other classes too. If you want more thorough feedback about how I think you could improve the class, I have quite a few ideas that I’m very willing to share. Just email me at john.n.morris@wsu.edu.


## Completed Issues/User Stories
Here are links to the issues that we completed in this sprint:
* https://github.com/shoobooshooboo/chore-tracker/issues/8
* https://github.com/shoobooshooboo/chore-tracker/issues/7
* https://github.com/shoobooshooboo/chore-tracker/issues/3
* https://github.com/shoobooshooboo/chore-tracker/issues/2
* https://github.com/shoobooshooboo/chore-tracker/issues/5

## Incomplete Issues/User Stories
Here are links to issues we worked on but did not complete in this sprint:
* https://github.com/shoobooshooboo/chore-tracker/issues/12 <<Unfinished because it relies on front end>>
* https://github.com/shoobooshooboo/chore-tracker/issues/10 <<Lack of time>>
* https://github.com/shoobooshooboo/chore-tracker/issues/20 <<Lack of time>>
* https://github.com/shoobooshooboo/chore-tracker/issues/18 <<Lack of time>>
* https://github.com/shoobooshooboo/chore-tracker/issues/19 <<Lack of time>>
* https://github.com/shoobooshooboo/chore-tracker/issues/9 <<Lack of time>>
* https://github.com/shoobooshooboo/chore-tracker/issues/17 <<Lack of time>>

## Code Files for Review
Please review the following code files, which were actively developed during this sprint, for quality:
* [app.cpp](https://github.com/shoobooshooboo/chore-tracker/blob/dev-backend/app.cpp)
* [chore.hpp](https://github.com/shoobooshooboo/chore-tracker/blob/dev-backend/chore.hpp)
* [household.cpp](https://github.com/shoobooshooboo/chore-tracker/blob/dev-backend/household.cpp)
* [household.hpp](https://github.com/shoobooshooboo/chore-tracker/blob/dev-backend/household.hpp)
* [household_manager.cpp](https://github.com/shoobooshooboo/chore-tracker/blob/dev-backend/household_manager.cpp)
* [household_manager.hpp](https://github.com/shoobooshooboo/chore-tracker/blob/dev-backend/household_manager.hpp)
* [user_manager.hpp](https://github.com/shoobooshooboo/chore-tracker/blob/dev-backend/user_manager.hpp)
* [user_manager.cpp](https://github.com/shoobooshooboo/chore-tracker/blob/dev-backend/user_manager.cpp)
* [backend.cpp](https://github.com/shoobooshooboo/chore-tracker/blob/dev-frontend/ChoreTracker/backend.cpp)
* [backend.h](https://github.com/shoobooshooboo/chore-tracker/blob/dev-frontend/ChoreTracker/backend.h)
* [main.cpp](https://github.com/shoobooshooboo/chore-tracker/blob/dev-frontend/ChoreTracker/main.cpp)


## Retrospective Summary
Here's what went well:
* We got the basic stuff done

Here's what we'd like to improve:
* More motivation and time

Here are changes we plan to implement in the next sprint:
* Actually integrating front end and back end
* Making all of the UI Pages