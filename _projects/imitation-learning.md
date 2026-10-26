---
layout: page
title: Imitation learning
description: Training a robot to twist open a medicine bottle from human demonstration.
img: assets/img/research/openbottle.png
importance: 4
related_publications: true
---
<p class="text-muted">Center for Vision, Cognition, Learning, and Autonomy, UCLA · December 2015 – February 2017</p>

- Captured the complex hand forces humans use to open seven different medicine bottles with a tactile glove covered in IMUs (inertial measurement units) and force sensors.
- Constructed a robot action planner using a haptic network, an And-Or Graph, and the generalized Earley parser.
- Result: questioned the common structure humans see in the procedure to open any medicine bottle versus the widely varying forces and action sequences the robot used for each bottle. This prompted an investigation of abstraction and generalization in [causal learning](/research/causal-learning/).

**Engineering contributions**

- Neural network training for action planning and embodiment mapping between a human demonstrator and a robot.
- Localization using SLAM, IMU, and wheel odometry, combined with Kalman filtering, using a Microsoft Kinect and a Velodyne VLP-16.
- ROS navigation stack, including a dynamic footprint based on the current position of the arms.

<div class="mb-4" style="aspect-ratio: 16 / 9;">
  <iframe src="https://player.vimeo.com/video/161556506" style="width: 100%; height: 100%; border: 0;" allow="fullscreen" allowfullscreen></iframe>
</div>

**Collaborators:** [Feng Gao](https://fen9.github.io/), [Hangxin Liu](https://liuhx111.github.io/), [Xu Xie](https://xuxie1031.github.io/), Matt Millar, [Siyuan Qi](http://web.cs.ucla.edu/~syqi/), [Yixin Zhu](http://www.yzhu.io/), Brandon Rothrock (NASA JPL), [Song-Chun Zhu](http://www.stat.ucla.edu/~sczhu/)

<span hidden>{% cite edmonds2017feeling %}; {% cite xie2018unsupervised %}; {% cite liu2017glove %}</span>
