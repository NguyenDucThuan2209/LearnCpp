/*------------------------------------------*/
// When you sit down to write a program, generally you have some kind of idea, which you'd like to write a program for. New programmers often have trouble figuring out how to convert that idea into actual code. But it turns out, you have many of the problem solving skills you need already, acquired from everyday life.
// The most important thing to remember (and hardest thing to do) is to design your program before you start coding. In many regards, programming is like architecture. What would happen if you tried to build a house without following an architectural plan? Odds are, unless you were very talented, you'd end up with a house that had a lot of problems: walls that were not straight, a leaky roof, etc. Similarly, if you try to program before you have a good game-plan moving forward, you'll likely find that your code has a lot of problems, and you'll have to spend a lot of time fixing problems that could have been avoided altogether with a little thinking ahead.
// A little up-front planning will save you both time and frustration in the long run.
// In this lesson, we'll layout a generalized approach for converting ideas into simple functional programs.
/*------------------------------------------*/
// DESIGN STEP 1: DEFINE YOUR GOAL
// In order to write a successful program, you first need to define what your goal is. Ideally, you should be able to state this in a sentence or two. It is often useful to express this as a user-facing outcome. For example:
//// Allow user to organize a list of names and associated phone numbers.
//// Generate randomized dungeons that will produce interesting looking caverns.
//// Generate a list of stock recommendations for stocks that have high dividends.
//// Model how long it takes for a ball dropped off a tower to hit the ground.
// Although this step seems obvious, it's also highly important. The worst thing you can do is write a program that doesn't actually do what you (or your boss) wanted!
/*------------------------------------------*/
// DESIGN STEP 2: DEFINE REQUIREMENTS
// While defining your problem helps you determine what outcome you want, it's still vague. The next step is to think about requirements.
// Requirements is fancy word for both the constraints that your solution needs to abide by (e.g. budget, timeline, space, memory, etc), as well as the capabilities that the program must exhibit in order to meet the users' needs. Note that your requirements should similarly be focused on the "what", not the "how".
// For example:
//// Phone numbers should be saved, so they can be recalled later.
//// The randomized dungeon should always contain a way to get from the entrance to an exit.
//// The stock recommendations should leverage historical pricing data.
//// The user should be able to enter the height of the tower.
//// We need a testable version within 7 days.
//// The program should produce results within 10 seconds of the user submitting their request.
//// The program should crash in less than 0.1% of user sessions.
// A single problem may yield many requirements, and the solution isn't "done" until it satisfies all of them.
/*------------------------------------------*/
// DESIGN STEP 3: DEFINE YOUR TOOLS, TARGETS, AND BACKUP PLAN
// When you are an experienced programmer, there are many other steps that typically would take place at this point, including: 
//// Defining what target architecture and/or OS your program will run on.
//// Determining what set of tools you will be using.
//// Determining whether you will write your program alone or as part of a team.
//// Defining your testing/feedback/release strategy.
//// Determining how you will back up your code.
// However, as a new programmer, the answers to these questions are typically simple: You are writing a program for your own use, alone, on your own system, using an IDE you downloaded, and your code is probably not used by anybody but you. This makes things easy.
// That said, if you are going to work on anything of non-trivial complexity, you should have a plan to backup your code. It's not enough to zip or copy your source directory to another location on the same storage device -- if your storage device dies or becomes corrupted, you will lose everything. Copying and zipping to removable storage (e.g. flash drive) is better, though you still risk losing everything in the event of theft, fire, or a significant natural disaster.
// The best backup strategy involves getting a copy of your code onto a machine that exists in a different physical location. There are lots of easy ways to do this: Zip it up and email it to yourself, upload it to a cloud storage service (e.g. Dropbox), use a file transfer protocol (e.g. SFTP) to upload it to a server you control, or use a version control system residing on another machine or in the cloud (e.g. Github). Version control systems have the added advantage of not only being able to restore your files, but also to roll them back to a previous version.
/*------------------------------------------*/
// DESIGN STEP 4: BREAK HARD PROBLEMS DOWN INTO EASY PROBLEMS
// In real life, we often need to perform tasks that are very complex. Trying to figure out how to do these tasks can be very challenging. In such cases, we often make use of the top down method of problem solving. That is, instead of solving a single complex task, we break that task into multiple subtasks, each of which is individually easier to solve. If those subtasks are still to difficult to solve, they can be broken down further. By continuously splitting complex tasks into simpler ones, you can eventually get to a point where each individual task is manageable, if not trivial.
//