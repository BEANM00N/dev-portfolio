---
title: SOL CONSTRUCT
date: 2026-06-14
summary: Pilot a Scrappy Aerial Combat Rig in a Rusty Survival Roguelite
tags:
  - Games
  - Unreal Engine
  - Blueprints
  - Tech Art
  - C++
  - AI
image:
  preview_only: true
toc: true
---

<style>
  /* 1. Set the fixed, darkened background image for the whole page */
  body {
    background-image: linear-gradient(rgba(15, 23, 42, 0.45), rgba(15, 23, 42, 0.55)), url('featured.jpg') !important;
    background-size: cover !important;
    background-attachment: fixed !important;
    background-position: center !important;
  }

  /* 2. Wrap your content in a premium "glass" card */
  article {
    background-color: rgba(30, 41, 59, 0.6) !important;
    backdrop-filter: blur(12px);
    -webkit-backdrop-filter: blur(12px);
    border: 1px solid rgba(255, 255, 255, 0.1);
    border-radius: 1.5rem;
    padding: 3rem;
    margin-top: 3rem;
    margin-bottom: 3rem;

    /* Widens and centers the island */
    width: 100% !important;
    max-width: 950px !important; 
    margin-left: auto !important;
    margin-right: auto !important;
  }

  /* Prevent browser anchor jumps from overshooting */
  article h2, article h3 {
    scroll-margin-top: 120px !important;
  }

  /* 3. Table of Contents - Glass Card & Links */
  .hb-toc > div {
    background-color: rgba(30, 41, 59, 0.6) !important;
    backdrop-filter: blur(12px);
    -webkit-backdrop-filter: blur(12px);
    border-radius: 1rem;
    padding: 1.5rem !important;
    border-left: 4px solid #e05e5e !important; 
    height: fit-content !important; 
    margin-top: 3rem !important;
  }

  .hb-toc p {
    color: white !important;
    font-size: 1.1rem !important;
    margin-bottom: 1rem !important;
    font-weight: 600 !important;
    text-transform: none !important;
  }

  .hb-toc ul {
    list-style: none !important;
    padding-left: 0 !important;
    margin: 0 !important;
  }
  
  .hb-toc ul ul {
    padding-left: 1rem !important; 
  }

  .hb-toc a {
    color: #94a3b8 !important; 
    text-decoration: none !important;
    display: block !important;
    padding: 0.35rem 0.8rem !important;
    border-radius: 9999px !important; 
    transition: all 0.2s ease-in-out;
    margin-bottom: 0.25rem !important;
    font-size: 0.9rem !important;
    border: 1px solid transparent !important; 
  }

  .hb-toc a:hover {
    color: white !important;
    background-color: rgba(255, 255, 255, 0.05) !important;
  }

  /* --- GUARANTEED RED PILL ACTIVE STATE --- */
  .hb-toc a.red-pill-active {
    color: white !important;
    border: 1px solid #e05e5e !important; 
    background-color: transparent !important;
  }

  /* ========================================== */
  /* TONY'S HIGHLIGHTS & TAGS CSS               */
  /* ========================================== */

  /* Hide the native Hugo Blox tags block at the very bottom */
  .article-tags, 
  .pub-tags, 
  div:has(> a[href*="/tags/"]) {
    display: none !important;
  }

  /* Indented Blurb Styling */
  .tony-blurb {
    border-left: 4px solid #e05e5e;
    padding-left: 1.5rem;
    margin: 1.5rem 0 2.5rem 0;
    font-size: 1.15rem;
    line-height: 1.6;
    color: #94a3b8;
    font-style: italic;
  }

  /* Specs & Tech Tag Rows */
  .tony-specs-container {
    display: flex;
    flex-direction: column;
    gap: 0.8rem;
    margin-bottom: 2.5rem;
  }

  .tony-spec-row {
    display: flex;
    align-items: center;
    gap: 1rem;
    color: white;
  }

  .tony-spec-row i {
    width: 24px;
    font-size: 1.25rem;
    text-align: center;
    color: #cbd5e1;
  }

  /* Custom Pill Buttons */
  .tony-pill {
    padding: 0.25rem 0.8rem;
    border-radius: 0.35rem;
    font-size: 0.85rem;
    font-weight: 700;
    letter-spacing: 0.025em;
  }

  .tony-pill.blue {
    background-color: #0070f3;
    color: white;
  }

  .tony-pill.black {
    background-color: #000000;
    color: white;
    border: 1px solid rgba(255, 255, 255, 0.15);
  }

  /* Highlights Card Box */
  .tony-highlights-card {
    background-color: rgba(30, 41, 59, 0.2);
    border: 2px solid rgba(224, 94, 94, 0.35);
    border-radius: 1rem;
    padding: 2rem;
    margin-bottom: 3rem;
  }

  .tony-highlights-card h3 {
    color: white !important;
    font-size: 1.35rem !important;
    font-weight: 700 !important;
    margin-top: 0 !important;
    margin-bottom: 1.25rem !important;
    display: flex;
    align-items: center;
    gap: 0.6rem;
  }

  .tony-highlights-card h3 i {
    color: #e05e5e;
  }

  .tony-highlights-card ul {
    list-style-type: disc !important;
    padding-left: 1.5rem !important;
    margin: 0 !important;
  }

  .tony-highlights-card li {
    color: #cbd5e1 !important;
    margin-bottom: 0.85rem !important;
    line-height: 1.6;
    font-size: 1rem;
  }

  .tony-highlights-card li:last-child {
    margin-bottom: 0 !important;
  }

  /* Specific Keyword Highlight Text */
  .keyword-red {
    color: #e05e5e;
    font-weight: 600;
  }

  /* Base text shrinking for elegance */
  article p, 
  article li {
    font-size: 0.95rem !important; 
    line-height: 1.6 !important;   
  }

  /* Image Captions */
  article figcaption {
    font-size: 0.85rem !important; 
    line-height: 1.4 !important;
    opacity: 0.8; 
    text-align: center;
  }
  article figcaption p {
    font-size: inherit !important; 
    margin-bottom: 0 !important;
  }

  /* ========================================== */
  /* COLLAPSIBLE CODE BLOCKS CSS                */
  /* ========================================== */
  details.code-dropdown {
    background: rgba(30, 41, 59, 0.4);
    border: 1px solid rgba(255, 255, 255, 0.1);
    border-radius: 0.5rem;
    margin-top: 1rem;
    margin-bottom: 1.5rem;
    overflow: hidden;
  }

  details.code-dropdown summary {
    padding: 1rem;
    font-weight: 600;
    color: #e05e5e;
    cursor: pointer;
    user-select: none;
    outline: none;
    transition: background 0.2s ease;
  }

  details.code-dropdown summary:hover {
    background: rgba(255, 255, 255, 0.05);
  }

  details.code-dropdown .highlight {
    margin: 0 !important;
    border-radius: 0 0 0.5rem 0.5rem;
  }

  details.code-dropdown .highlight pre {
    background-color: rgba(10, 15, 24, 0.95) !important;
    padding: 1.25rem !important;
  }

  details.code-dropdown .highlight code {
    font-size: 0.8rem !important;
    line-height: 1.5 !important;
  }
  .clean-carousel {
    display: flex;
    gap: 1.5rem;
    overflow-x: auto;
    padding: 1rem 0;
    scroll-snap-type: x mandatory;
    scrollbar-width: thin;
    scrollbar-color: #e05e5e rgba(255, 255, 255, 0.05);
  }
  .clean-carousel a {
    flex: 0 0 85%;
    max-width: 600px;
    scroll-snap-align: center;
    text-decoration: none !important;
    display: flex;
    flex-direction: column;
  }
  .clean-carousel img {
    width: 100%;
    height: 350px;
    object-fit: cover;
    border-radius: 1rem;
    border: 1px solid rgba(255, 255, 255, 0.1);
    box-shadow: 0 10px 30px rgba(0,0,0,0.5);
    transition: transform 0.2s ease, border-color 0.2s ease;
    margin: 0 !important;
  }
  .clean-carousel img:hover {
    transform: scale(1.02);
    border-color: #e05e5e;
  }
  .clean-carousel-caption {
    text-align: center;
    font-size: 0.85rem;
    color: #94a3b8;
    font-style: italic;
    margin-top: 0.75rem;
  }

</style>

<script>
  document.addEventListener('DOMContentLoaded', () => {
    // Table of Contents Scroll Highlighting
    const observer = new IntersectionObserver((entries) => {
      entries.forEach(entry => {
        const id = entry.target.getAttribute('id');
        const link = document.querySelector(`.hb-toc a[href="#${id}"]`);
        
        if (entry.isIntersecting && link) {
          document.querySelectorAll('.hb-toc a').forEach(l => l.classList.remove('red-pill-active'));
          link.classList.add('red-pill-active');
        }
      });
    }, { rootMargin: '-20% 0px -70% 0px' });

    document.querySelectorAll('article h2, article h3').forEach(h => observer.observe(h));
  });
</script>

<div class="tony-blurb">
A high stakes SinglePlayer Survival Roguelite. Pilot a sentient flight combat rig built for survival in a decaying metal world. Obliterate your foes, harvest their scrap, and rebuild to survive.</div>

<div class="tony-specs-container">
  <div class="tony-spec-row">
    <i class="fas fa-desktop"></i>
    <span class="tony-pill blue">Windows</span>
  </div>
  
  <div class="tony-spec-row">
    <i class="fas fa-code"></i>
    <span class="tony-pill blue">C++</span>
    <span class="tony-pill blue">Blueprints</span>
    <span class="tony-pill blue">FLECS ECS</span>
  </div>
  
  <div class="tony-spec-row">
    <i class="fas fa-laptop-code"></i>
    <span class="tony-pill black">Unreal Engine 5</span>
    <span class="tony-pill black">AI & Pathfinding</span>
    <span class="tony-pill black">Tech Art</span>
  </div>
</div>

<div style="border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5); margin-bottom: 3rem;">
  {{< youtube RBfGwsypPt4 >}}
</div>

<div class="tony-highlights-card">
  <h3><i class="far fa-star"></i> Contributions</h3>
  <ul>
    <li><span class="keyword-red">Custom Enemy ecosystem</span> with air and ground units.</li>
    <li>Core player flight, built with a tonne of playtesting, removing disorienting axis to create an intuitive flight model, using a custom replicatable movement component</li>
    <li>A super optimised projectile system using the <span class="keyword-red">FLECS C++ library</span>.</li>
    <li>An <span class="keyword-red">Async Pathfinding and Utility EQS</span> implementation for dynamic flight awareness.</li>
    <li>Developed an internal Plugin for procedural texture generation.</li>
    <li>Enemy <span class="keyword-red">behaviour, models, animation blueprints, weapons, health/armor components</span>.</li>
    <li>Artyle iteration and <span class="keyword-red">3D Art Tests</span>.</li>
  </ul>
</div>

## Overview

SOL CONSTRUCT is the culmination of nearly 3 years of professional game development, encompassing all the triumphs, failures, and harsh lessons learned along the way. After oiginally setting out to make a flying game ([SOL DRIFT](http://localhost:1313/dev-portfolio/projects/sol-drift/)), we explored numerous genres before circling back to our roots, but this time with a hardened design philosophy.

As a small team, we had to evaluate every mechanic on a "Bang for Buck" basis. We realised early on that the highest degree of excitement and variation in our gameplay loop would come directly from our enemies. No matter our capacity for level design or weapon crafting, our core pillar became creating AI that dynamically exploits and challenges the player's actions. 

## Iterating the Player Flight Model

During the first few months of development, player movement was the most heavily debated feature. I originally implemented Gyro Aim and full 6 Degrees of Freedom (6DOF). However, playtests revealed it was even more polarising than Marmite. Some players really grasped it, but many simply spun out. We realised that trying to cram standard flight sim conventions into an arcade action space was actively fighting the player’s intuition, at least in our game. [Delivery Complete](https://store.steampowered.com/app/3639060/DELIVERY_MUST_COMPLETE/) actually managed to implement it in a way that looks so cool, and frankly looks way more satisfying than what we had.


<div style="margin-bottom: 0.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <img src="Module Spin Sped Up.gif" class="zoomable" alt="Module Randomiser Render" style="width: 100%; height: auto; display: block; margin: 0 !important;" />
</div>


Our solution was to strip it back. We removed roll and the ability to fly completely upside down, pivoting to a movement style akin to Minecraft’s creative mode or Interplay's Descent. While it was tough to say goodbye to true 6DOF, this restriction immediately gave players total, intuitive control over their positioning. We matched this mechanically with a modular ship design. A central frame where wings, thrusters, and turrets attach, heavily utilising procedural animation to make the craft feel responsive and weighty.

You can have a peep on what our anim graph looks like. Nothing too complex, but it adds a lot of juice:
<details class="code-dropdown">
  <summary><i class="fas fa-code"></i> Player Mesh Anim BP</summary>
{{< blueprint src="LFTR Frame Anim BP.txt" >}}

</details>

## Designing a Flying Enemy Ecosystem

Designing flying enemies is a completely different beast compared to grounded AI. Because they have an entire Z axis of open space to utilise, restricting them and giving them purpose was my biggest design hurdle. To solve this, I modeled our enemy roster after chess pieces (definitely inspired by DOOM!), categorised by their effective engagement distances: **Stationary, Long Range, Medium, and Close Range**. 
  
</style>

<div class="clean-carousel">

<a data-fancybox="gallery" href="riveter.png" data-caption="The Riveter applying localized pressure.">
    <img src="riveter.png" alt="Riveter">
    <div class="clean-carousel-caption">The Riveter applying localized pressure.</div>
  </a>

  <a data-fancybox="gallery" href="rocket drone.png" data-caption="High-mobility Rocket Drone for explosive interception.">
    <img src="rocket drone.png" alt="Rocket Drone">
    <div class="clean-carousel-caption">High-mobility Rocket Drone for explosive interception.</div>
  </a>

  <a data-fancybox="gallery" href="Cannon LFTR.png" data-caption="Heavy artillery Cannon LFTR engaging from a distance.">
    <img src="Cannon LFTR.png" alt="Cannon LFTR">
    <div class="clean-carousel-caption">Heavy artillery Cannon LFTR engaging from a distance.</div>
  </a>

  <a data-fancybox="gallery" href="Saw.png" data-caption="The terrifying close-range Saw enemy designed to embed and disable.">
    <img src="Saw.png" alt="Saw Enemy">
    <div class="clean-carousel-caption">The terrifying close-range Saw enemy designed to embed and disable.</div>
  </a>

  <a data-fancybox="gallery" href="sentry.png" data-caption="The aerial Sentry unit patrolling the perimeter.">
    <img src="sentry.png" alt="Sentry">
    <div class="clean-carousel-caption">The aerial Sentry unit patrolling the perimeter.</div>
  </a>

  <a data-fancybox="gallery" href="HeavyCrawler.png" data-caption="The heavily armored Crawler unit.">
    <img src="HeavyCrawler.png" alt="Heavy Crawler">
    <div class="clean-carousel-caption">The heavily armored Crawler unit.</div>
  </a>

</div>

My golden rule for designing and implementing *every* new enemy was asking: *"What action am I trying to exploit from the player?"*

For example:
* **Long-range enemies** are designed to encourage and exploit the player's dash.
* **Short-range enemies** force the player to constantly reconsider their spatial positioning.

<div style="margin-bottom: 0.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <img src="MeleeDroneSpedUp.gif" class="zoomable" alt="Module Randomiser Render" style="width: 100%; height: auto; display: block; margin: 0 !important;" />
</div>

Because we always wanted a minimum level of enemy density in encounters, these units had to complement each other. They don't necessarily "communicate" via code, but their roles naturally synergise. For example, I recently implemented a close range "Saw" enemy that embeds itself in the player, dealing tick damage but, more importantly, *disabling the player's dash and dodge*. If left unchecked, this allows the Long Range sniper enemies (who usually miss a dashing player) to easily land devastating hits. This encourages the player to approach encounters strategically, prioritising targets based on the specific restrictions their synergy imposes.

<div style="margin-bottom: 0.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <img src="EnemyGangSpedUp.gif" class="zoomable" alt="Module Randomiser Render" style="width: 100%; height: auto; display: block; margin: 0 !important;" />
</div>

## Frankensteined Pathfinding & EQS

To bring these designs to life, the AI needed to understand 3D space. I frankensteined an existing [pathfinding plugin](https://github.com/NonStaticGH/CPathHostProject) combining Sparse Voxel Octrees with A* Pathfinding. 

**The Async Solution:** Initially, synchronous pathfinding calls choked our Game Thread, causing massive stutters if multiple enemies requested paths simultaneously. By moving to an Async solution, I smoothed out the frame rate, carefully tuning the graph update rates to avoid garbage collection hitches.

**EQS Implementation:** I replaced our early, hacky target tracking with a much more robust Environment Query System (EQS). Enemies now transition through Patrolling, Searching, and Attacking states based on true Perception (hearing, damage, visibility). Using Dot product math, I programmed enemies to evaluate points based on the player's orientation, allowing them to intelligently flank or close distance dynamically based on their role. This single feature completely blew our minds and gave us so much motivation to move forward.

<div style="margin-bottom: 2.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5); background-color: rgba(15, 23, 42, 0.4);">
  <img src="eqsnode.png" class="zoomable" alt="Module Randomiser Render" style="width: 100%; height: auto; display: block; margin: 0 !important;" />
  <div style="padding: 0.75rem 1rem; text-align: center; font-size: 0.85rem; color: #94a3b8; font-style: italic;">
    *Query used by medium range enemies.*
  </div>
</div>

<details class="code-dropdown">
  <summary>EQS Medium Range Query breakdown</summary>


**Volumetric grid Generation:** The query generates a large 3D spherical grid of potential movement locations (a 3000-unit radius with 500-unit spacing), giving the flying AI a full 6 Degrees of Freedom (6DOF) spatial canvas to evaluate.

E**nvironmental & Range Filtering:** It utilizes a boolean Trace test to immediately cull any points obstructed by world geometry (ensuring a clear line of sight to the player) alongside a strict Distance filter to discard points outside the enemy's effective combat range.

**"Smart" Positioning via Dot Product:** The remaining viable points are scored using an Inverse Linear Distance modifier and a Dot Product test. This mathematically evaluates points relative to the player's facing direction, driving the AI to intelligently flank or prioritize specific angles of attack rather than simply flying straight at the target.
</details>

## Streamlining the Pipeline (ProcTex Plugin)

To get that crunchy aesthetic without bottlenecking production, I developed a custom Editor Utility Plugin. Rather than going in and out of Substance Painter for every asset, ProcTex allows us to down res, posterize, and manipulate textures with a real time 3D preview directly inside the Unreal Editor. This tool single handedly sped up our asset creation pipeline, allowing the team to generate game ready materials in minutes. You can find more deets on it [here](https://beanm00n.github.io/dev-portfolio/projects/procedural-texture-baker/).

