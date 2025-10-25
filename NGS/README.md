# Nitro Ground Shaker
Nitro Ground Shaker Pinball Machine ruleset basically factory rules rewritten to add new audio and shaker motor integration.
TODO -
* Top Arrows - Starts on the Right side (LAMP_TOP_ARROW_LEFT) switches with POPs, Rubber, Spinner, SLings to (LAMP_TOP_ARROW_RIGHT).

*When the center Saucer is hit the corresponding lower left arrow is lit (LAMP_COLLECT_BONUS_LEFT)
(LAMP_COLLECT_BONUS_RIGHT). When both of the arrows have been lit the top center Arrow (LAMP_TOP_ARROW_CENTER) is lit and the center scaucer scoores 5000. Resets every ball.

* Double Bonus - At the start of the game the lamp (LAMP_DOUBLE_BONUS_TOP) is on. Lamp toggles with POPs, Rubber, Spinner, SLings. When lit the center saucer lites double bonus lamp (LAMP_DOUBLE_BONUS_BOTTOM).This toggle does not reset ball to ball.

* Bonus Collect - Trevor working on Count up and count down function.

* Shaker Motor - PWM with 5 switch inputs to a 12V output. 2 Saucers, Drop Target Bank complete, Flippers to "rev engine" prior to switch hit. None of this is set in stone, just getting something written down ?