// Experience page entries, newest first. `org` and bullets may contain inline HTML.
export interface Role {
  title: string;
  org: string;
  dates: string;
  location?: string;
  bullets?: string[];
}

export const work: Role[] = [
  {
    title: 'Staff AI/ML Applied Scientist',
    org: '<a href="https://www.gm.com">General Motors</a>',
    dates: 'February 2026 – present',
    location: 'Remote',
    bullets: [
      'Develop end-to-end driving models trained with imitation and self-play reinforcement learning.',
      'Joined GM through its acquisition of Cruise.',
    ],
  },
  {
    title: 'Senior Applied Scientist II',
    org: '<a href="https://en.wikipedia.org/wiki/Cruise_(autonomous_vehicle)">Cruise</a>',
    dates: 'April 2024 – February 2026',
    location: 'Remote',
    bullets: [
      'Co-developed <a href="/papers/ICML25_DriveGPT.pdf">DriveGPT</a>, scaling autoregressive behavior models for driving to 1.4B parameters and 120M training segments (~50x more data than prior published models); demonstrated data and model scaling laws for driving (ICML 2025).',
      'Applied imitation and reinforcement learning to trajectory generation for motion planning.',
      'Distilled large behavior models into compact models for on-vehicle deployment.',
      'Co-inventor on a patent application for autoregressive models for autonomous agents (<a href="/papers/US20260131822A1.pdf">US 2026/0131822 A1</a>).',
    ],
  },
  {
    title: 'Senior Applied Scientist',
    org: '<a href="https://en.wikipedia.org/wiki/Cruise_(autonomous_vehicle)">Cruise</a>',
    dates: 'October 2021 – April 2024',
    location: 'Remote',
    bullets: [
      'Worked at the intersection of machine learning and motion planning on the Behavior Planning team, starting with maneuver planning.',
      'Applied imitation learning to trajectory generation for behavior planning; used PyTorch and ROS to deploy safer, more capable ML models to vehicles driving on public roads.',
    ],
  },
  {
    title: 'Director and President',
    org: 'Center for AI and Robot Autonomy (CARA)',
    dates: 'March 2021 – May 2025',
    bullets: ['Defined updated mission and vision statements, sought alternative funding, and maintained 501(c)(3) status.'],
  },
  {
    title: 'Graduate Student Researcher',
    org: 'Computer Science Department, UCLA',
    dates: 'September 2016 – September 2021',
    location: 'Los Angeles, CA',
    bullets: [
      '<a href="/research/causal-learning/">Causal learning</a>: built <a href="https://github.com/mjedmonds/OpenLock">OpenLock</a>, an open-source virtual escape room in which every room shares an abstract causal structure while surface features change. Ran human-subject experiments showing people discover and transfer that structure, and developed a hierarchical Bayesian model that matched human transfer while seven model-free RL algorithms failed (AAAI 2020 oral; CogSci 2018 oral; CogSci 2019).',
      '<a href="/research/imitation-learning/">Imitation learning</a>: taught a robot to open medicine bottles from human demonstrations by integrating force and pose, captured with a custom tactile glove and planned with an embodied haptic model and a stochastic grammar (IROS 2017, two papers).',
      '<a href="/research/explainable-ai/">Explainable AI</a>: extended the bottle-opening robot to explain its own behavior; showed that the explanations that best foster human trust differ from the components that drive task performance (Science Robotics 2019).',
      'Also contributed to abstract causal reasoning (CVPR 2021) and in situ human-robot value alignment (Science Robotics 2022).',
    ],
  },
  {
    title: 'Adjunct Professor',
    org: 'Santa Monica College',
    dates: 'June 2016 – September 2021',
    bullets: [
      'Taught one or two 45-student classes per quarter: led lectures, held office hours, and created course materials.',
      'Instructed 25 courses: Internet Programming (HTML, CSS, JavaScript, MySQL, and PHP), Intro to C, and Intro to C++. See <a href="/teaching/">teaching</a>.',
    ],
  },
  {
    title: 'Robotics Research Engineer Intern',
    org: 'Center for AI and Robot Autonomy (CARA)',
    dates: 'June 2018 – March 2020',
    bullets: ['Worked on a representation learning project coupling vision and language (see <a href="/research/language/">research</a>).'],
  },
  {
    title: 'Teaching Assistant',
    org: 'Computer Science Department, UCLA',
    dates: 'September 2015 – June 2016',
    bullets: ['Introduction to C and Introduction to C++: led discussion sections (~50 students) and held office hours.'],
  },
  {
    title: 'Teaching Assistant',
    org: 'Electrical &amp; Computer Engineering Department, University of Dayton',
    dates: 'January 2015 – May 2015',
    bullets: ['Electronic Devices Lab: aided in lab sessions (~40 students).'],
  },
  {
    title: 'Software Engineering Intern',
    org: 'Garmin International',
    dates: 'May 2013 – August 2013',
    bullets: [
      'Automated the testing process for small-craft airplane ACARS systems that send timed status messages to ground stations.',
      'Reduced testing time by 40% and saved hundreds of vendor certification testing hours by optimizing simulation timing protocols while adhering to FAA safety standards.',
    ],
  },
  {
    title: 'Enrichment Workshop Tutor',
    org: 'School of Engineering, University of Dayton',
    dates: 'September 2012 – May 2015',
    bullets: ['Tutored first-year engineering students in calculus, chemistry, and physics; led a team of 8 tutors overseeing 40 students.'],
  },
  {
    title: 'Summer School Teacher',
    org: 'Cristo Rey Kansas City',
    dates: 'May 2011 – August 2012',
    bullets: ['Taught four junior and senior classes at a prep school focused on college placement for underrepresented groups.'],
  },
];

export const education: Role[] = [
  {
    title: 'PhD in Computer Science, Artificial Intelligence concentration',
    org: 'University of California, Los Angeles',
    dates: 'September 2021',
    bullets: [
      'Dissertation: <a href="/papers/mjedmonds___PhD_Dissertation.pdf"><em>Learning How and Why: Causal Learning and Explanation from Physical, Interactive, and Communicative Environments</em></a>',
    ],
  },
  {
    title: 'M.S. in Computer Science',
    org: 'University of California, Los Angeles',
    dates: 'June 2017',
    bullets: ['Thesis: <a href="https://escholarship.org/uc/item/1r15v023"><em>Learning Complex Functional Manipulations by Human Demonstration and Fluent Discovery</em></a>'],
  },
  {
    title: 'B.S. in Computer Engineering, Magna Cum Laude',
    org: 'University of Dayton',
    dates: 'May 2015',
    bullets: ['Thesis: <a href="/papers/SNPD_2015_HighPerformanceDM_final.pdf"><em>High-Performance Declarative Memory through MapReduce</em></a>'],
  },
];
