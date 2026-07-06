---
title: SOL DRIFT
date: 2024-02-16
summary: Starfox meets Doom. a fusion of the classic arcade flight genre and the
  modern arena shooter.
tags:
  - Games
  - Unreal Engine
  - Blueprints
  - Tech Art
image:
  preview_only: true
toc: true

---

<style>
  /* 1. Set the fixed, darkened background image for the whole page */
  body {
    background-image: linear-gradient(rgba(15, 23, 42, 0.45), rgba(15, 23, 42, 0.55)), url('featured.png') !important;
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
  }

  /* 3. Custom Action Button */
  .custom-play-btn {
    display: inline-flex;
    align-items: center;
    gap: 0.6rem;
    padding: 0.6rem 1.25rem; 
    border: 2px solid #e05e5e; 
    border-radius: 0.5rem;
    color: white !important;
    text-decoration: none !important;
    font-weight: 600;
    font-size: 1.1rem;
    line-height: 1 !important; 
    background-color: transparent;
    transition: all 0.2s ease-in-out;
    margin-bottom: 2rem;
  }
  
  .custom-play-btn:hover {
    background-color: #e05e5e; 
    color: white !important;
  }
  
  .custom-play-btn img {
    width: 1.25rem !important;
    height: 1.25rem !important;
    object-fit: contain;
    display: block;
    margin: 0 !important; 
  }

  /* Prevent browser anchor jumps from overshooting */
  article h2, article h3 {
    scroll-margin-top: 120px !important;
  }

  /* 4. Table of Contents - Glass Card & Links */
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

  article p, 
  article li {
    font-size: 0.95rem !important; 
    line-height: 1.6 !important;   
  }

</style>

<script>
  document.addEventListener('DOMContentLoaded', () => {
    const observer = new IntersectionObserver((entries) => {
      entries.forEach(entry => {
        const id = entry.target.getAttribute('id');
        const link = document.querySelector(`.hb-toc a[href="#${id}"]`);
        
        // When a heading enters the view, highlight its link
        if (entry.isIntersecting && link) {
          document.querySelectorAll('.hb-toc a').forEach(l => l.classList.remove('red-pill-active'));
          link.classList.add('red-pill-active');
        }
      });
    }, { rootMargin: '-20% 0px -70% 0px' });

    // Track all H2 and H3 headings inside the article
    document.querySelectorAll('article h2, article h3').forEach(h => observer.observe(h));
  });
</script>

<a href="https://mad-moon-studios.itch.io/shoot-to-die" class="custom-play-btn" target="_blank">
  <img src="https://static.itch.io/images/itchio-textless-white.svg" alt="Itch.io logo">
  Play
</a>

<div class="tony-blurb">
  Engage in lightning-fast omnidirectional vehicle dogfights inside a colossal decaying mechanism. Secure rare blueprints, deploy active countermeasures, and extract your stash via cargo drones before the automated system adapts.
</div>

<div class="tony-specs-container">
  <div class="tony-spec-row">
    <i class="fas fa-desktop"></i>
    <span class="tony-pill blue">Windows (PC)</span>
  </div>
  
  <div class="tony-spec-row">
    <i class="fas fa-code"></i>
    <span class="tony-pill blue">Blueprints</span>
    <span class="tony-pill blue">FMOD Integration</span>
    <span class="tony-pill blue">GPU Shaders</span>
  </div>
  
  <div class="tony-spec-row">
    <i class="fas fa-laptop-code"></i>
    <span class="tony-pill black">Unreal Engine 5</span>
    <span class="tony-pill black">Niagara Particles</span>
    <span class="tony-pill black">Vehicle Physics</span>
  </div>
</div>

<div class="tony-highlights-card">
  <h3><i class="far fa-star"></i> Contributions</h3>
  <ul>
    <li>Experimented with a <span class="keyword-red">Niagara GPU Projectile Pooling system</span>, optimising bullet hell density and shapes with a 90% gain in performance.</li>
    <li>Migrated movement into a custom <span class="keyword-red">weighty, momentum driven flight Pawn script</span>, giving us full control over game feel.</li>
    <li>Programmed spatial <span class="keyword-red">3D obstacle detection systems</span> and reactive countermeasure logic loop, all used in behaviour trees.</li>
    <li>Developed the full meta progression loop featuring an integrated <span class="keyword-red">\"C.A.R.D. Upgrade Architecture\"</span>, localised stat scoreboard saves, and level selections.</li>
    <li>Designed the structural logic for a comprehensive <span class="keyword-red">modular garage setup terminal</span> to safely equip nose, wing, armor, and utility modules between runs, as well as store puzzles, cyphers and world interactions.</li>
  </ul>

  <div style="border-top: 1px solid rgba(255, 255, 255, 0.1); margin: 1.5rem 0 1rem 0; padding-top: 1rem;">
    <h4 style="color: white; font-size: 1rem; font-weight: 600; margin-bottom: 0.75rem; letter-spacing: 0.05em; text-transform: uppercase; opacity: 0.8;">
      <i class="fas fa-tools" style="font-size: 0.85rem; margin-right: 0.4rem; color: #e05e5e;"></i>Honorable Mentions:
    </h4>
    <ul style="list-style-type: none !important; padding-left: 0 !important; display: grid; grid-template-columns: repeat(auto-fit, minmax(280px, 1fr)); gap: 0.6rem;">
      <li style="font-size: 0.85rem !important; color: #94a3b8 !important; display: flex; align-items: flex-start; gap: 0.5rem; margin-bottom: 0 !important;">
        <span style="color: #e05e5e;">▪</span> Native material code driving real time raymarched volumetrics.
      </li>
      <li style="font-size: 0.85rem !important; color: #94a3b8 !important; display: flex; align-items: flex-start; gap: 0.5rem; margin-bottom: 0 !important;">
        <span style="color: #e05e5e;">▪</span> Automated gimbal aiming and  crosshair stabilisation parameters.
      </li>
      <li style="font-size: 0.85rem !important; color: #94a3b8 !important; display: flex; align-items: flex-start; gap: 0.5rem; margin-bottom: 0 !important;">
        <span style="color: #e05e5e;">▪</span> Automated countermeasure responses like Chaff, Mines, Drone Swarms.
      </li>
      <li style="font-size: 0.85rem !important; color: #94a3b8 !important; display: flex; align-items: flex-start; gap: 0.5rem; margin-bottom: 0 !important;">
        <span style="color: #e05e5e;">▪</span> FMOD links implementing paramterised dynamic jet thruster events.
      </li>
      <li style="font-size: 0.85rem !important; color: #94a3b8 !important; display: flex; align-items: flex-start; gap: 0.5rem; margin-bottom: 0 !important;">
        <span style="color: #e05e5e;">▪</span> Responsive curved UI shader effects wrapping around the primary player screen viewport.
      </li>
    </ul>
  </div>
</div>

Every system inside SOL DRIFT has been iteratively tuned against physical playtesting datasets across numerous live convention show floors, resulting in a hyper-focused movement pipeline.

## Engineering the S.O.L Fighter: Weighty Physics Pawn & Omnidirectional Flight

To fulfill the vision of a vehicle that captures both mechanical weight and arcade agility, we abandoned standard engine character movement components in favor of a specialized physics-driven **Flight Pawn** blueprint. Shifting away from rigid directional vectors allowed the ship to dynamically interact with architectural boundaries using true momentum-preserving equations:
* **True 12-Axis Autonomy:** Programmed fully un-blocked movement trees supporting simultaneous forward, horizontal, and vertical displacement.
* **Drift Rotation Mechanics:** Developed custom dampening forces that slide the craft smoothly through corners during high-speed thruster maneuvers, providing a distinct feeling of drift inertia.
* **Kinetic Refinements:** Eliminated mechanical springarm deadzones and added custom screen-space recoil shifts that physically jar the vehicle hull during heavy output bursts.

<details class="code-dropdown">
  <summary><i class="fas fa-code"></i> View Blueprint Architecture: Velocity Decay & Thruster Interpolation</summary>
```json
// Logic detailing physics impulse handling for momentum preservation loops

</details>

## High-Density Combat: Niagara GPU Projectile Pooling

To support our bullet-hell design pillars without dragging down frame rates on standard hardware, standard actor-spawning loops were entirely replaced with a centralized **Universal Projectile Pooling Engine**. Spawning thousands of individual laser actors quickly bottlenecked the CPU thread due to heavy garbage collection polling and component initialization cycles.

Our optimized solution shifts calculation weights directly onto background calculation groups:
* **GPU-Bound Projectiles:** Weapon arrays fire directly into a unified projectile pool that interfaces seamlessly with Niagara particles.
* **Per-Particle Life Cycles:** Hit evaluation, environmental trace calculations, and damage events are linked right into Niagara scratchpad memory addresses, allowing for accurate spatial collision lookups.
* **Muzzle Optimization:** Bullet structures are handled in a single execution queue, containing automated minigun loop parameters and weapon dispersion logic that scales based on active movement velocity values.

## Adaptive AI: Voxel Obstacle Detection & Autonomous Drones

To ensure that enemies navigating open three-dimensional spaces felt smart, aggressive, and highly reactive, we built a custom behavior tree network from the ground up. Flying AI requires complex spatial lookups to prevent units from constantly colliding with internal superstructure geometry.

To solve this, we implemented a dedicated **3D Obstacle Detection System**. Drone sensors continuously cast raycasts into a predictive movement arc, allowing the AI to automatically bank away from geometry or find tight access channels during active combat loops. This intelligence layer drives a highly specialized roster of drone archetypes modeled closely after chess rules—highlighted by defensive hunter-killer arrays, automated sentries, and tactical decoy drones that deploy countermeasures to redirect player fire parameters.

## Atmospheric Rendering: Raymarched Lighting & Retro Shaders

To establish our visual direction of a grim, mechanical industrial wasteland, I built a custom post-processing post-rendering stack. Instead of basic skybox spheres, we developed a mathematical, **Shader-Driven SkyAtmosphere System**. This system utilizes real-time raymarched volumetric lighting calculations to scatter light realistically through heavy post-industrial dust and dense spatial nebulas.

To give the UI a tactile, industrial look, we implemented a screen-space pixel shader that creates a vintage **Curved CRT Screen Distortion** directly on the player's viewport. This retro-futuristic styling was optimized alongside our gameplay indicators—including dynamic damage vignettes and a radial target locking reticle that stretches and tracks bounding targets instantly across the screen.