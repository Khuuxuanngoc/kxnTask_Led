// #pragma once

// #include "kxnTask.h"

// DEFINE_TASK_STATE(khanhTest_KxnTask_Snippet){
//     khanhTest_KxnTask_Snippet_ON,
//     khanhTest_KxnTask_Snippet_OFF,
// };

// CREATE_TASK(khanhTest_KxnTask_Snippet)
// /*Add your variable here*/

// void setup()
// {
//     /*Add your code setup here*/
//     stop();
// }

// void loop()
// {
//     switch (getState())
//     {
//     case khanhTest_KxnTask_Snippet_ON:
//         /*code*/
//         kDelay(0);
//         setState(khanhTest_KxnTask_Snippet_OFF);
//         break;

//     case khanhTest_KxnTask_Snippet_OFF:
//         /*code*/
//         kDelay(0);
//         setState(khanhTest_KxnTask_Snippet_ON);
//         break;

//     default:
//         break;
//     }
// }

// void start()
// {
//     kxnTaskManager.add(this);
//     setState(khanhTest_KxnTask_Snippet_ON);
// }

// void stop()
// {
//     kDelay(0);
//     setStateIdle();
// }

// END

// #ifndef khanhTest_KxnTask_Snippet__H
// #define khanhTest_KxnTask_Snippet__H

// #include "kxnTask.h"

// DEFINE_TASK_STATE(khanhTest_KxnTask_Snippet){
//     khanhTest_KxnTask_Snippet_ON,
//     khanhTest_KxnTask_Snippet_OFF,
// };

// CREATE_TASK(khanhTest_KxnTask_Snippet)
// /*Add your variable here*/

// void setup()
// {
//     /*Add your code setup here*/
//     stop();
// }

// void loop()
// {
//     switch (getState())
//     {
//     case khanhTest_KxnTask_Snippet_ON:
//         /*code*/
//         kDelay(0);
//         setState(khanhTest_KxnTask_Snippet_OFF);
//         break;

//     case khanhTest_KxnTask_Snippet_OFF:
//         /*code*/
//         kDelay(0);
//         setState(khanhTest_KxnTask_Snippet_ON);
//         break;

//     default:
//         break;
//     }
// }

// void start()
// {
//     kxnTaskManager.add(this);
//     setState(khanhTest_KxnTask_Snippet_ON);
// }

// void stop()
// {
//     kDelay(0);
//     setStateIdle();
// }

// void runFast(){

// }

// END