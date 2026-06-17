---
title: "Shoot To Die"
date: 2025-11-10
summary: "A frantic, physically-driven arcade score-chaser where you juggle dice with a heavy revolver."
tags:
  - Games
  - Unreal Engine
  - Blueprints
  - Tech Art
  - Physics
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

<a href="https://mad-moon-studios.itch.io/shoot-to-die" class="custom-play-btn" target="_blank">
  <img src="https://static.itch.io/images/itchio-textless-white.svg" alt="Itch.io logo">
  Play
</a>

<div class="tony-blurb">
  A frantic, physically-driven arcade score-chaser where you juggle dice with a heavy revolver. Built part-time in just one week for the "Devs Under Duress" game jam, this prototype served as an experimental playground for highly tactile, physics-based interactions and crunchy retro aesthetics.
</div>

<div class="tony-specs-container">
  <div class="tony-spec-row">
    <i class="fas fa-desktop"></i>
    <span class="tony-pill blue">Windows</span>
  </div>
  
  <div class="tony-spec-row">
    <i class="fas fa-code"></i>
    <span class="tony-pill blue">Blueprints</span>
    <span class="tony-pill blue">Tech Art</span>
    <span class="tony-pill blue">Physics</span>
  </div>
  
  <div class="tony-spec-row">
    <i class="fas fa-laptop-code"></i>
    <span class="tony-pill black">Unreal Engine 5</span>
  </div>
</div>

<div class="tony-highlights-card">
  <h3><i class="far fa-star"></i> Highlights</h3>
  <ul>
    <li>Developed and scoped entirely within a <span class="keyword-red">single week</span> on a part-time schedule.</li>
    <li>Engineered a highly tactile, physics-driven interaction system, featuring <span class="keyword-red">manual weapon mechanics</span> and fully interactable environmental objects.</li>
    <li>Designed a dual-collision projectile system utilizing "wiff" velocities to allow players to <span class="keyword-red">juggle physics actors</span> dynamically in mid-air.</li>
    <li>Created the foundational procedural rendering shaders that eventually evolved into the fully-fledged <span class="keyword-red">ProcTex</span> Unreal Engine plugin.</li>
    <li>Translated complex mouse-to-world-space mathematics to drive custom player controllers and responsive UI elements.</li>
  </ul>
</div>

## Overview: From Top-Down to Skeet-Shooting

This project was born during the "Devs Under Duress" game jam in November. Our original pitch was a 3D top-down dice-rolling game called "Pay The Toll," where players would try to breach score thresholds across multiple rounds. However, as we started developing, the concept rapidly evolved into something much more kinetic: a 3D first-person arcade shooter where you use a revolver to skeet-shoot dice. It was an incredibly fun pivot, and knowing we only had a week to build it part-time forced us to focus purely on the "feel" of the game. It’s a prototype I am incredibly proud of and absolutely plan to revisit in the future.

## An Experiment in Tactility and Physics

Weirdly enough, this jam was my very first real dip into physics in Unreal Engine. I wanted the game to ooze tactility, communicating a heavy, mechanical feel through both the visual styling and the player mechanics. Almost everything on the player's tool bench and shop is physically interactable. 

This philosophy extended directly into our weapon design. Instead of a simple "click-to-shoot" mechanic, the revolver was heavily physicalized:
* The player has to hold the trigger to manually prime the hammer.
* You can hold 'R' to tilt the gun and physically check the cylinder for remaining rounds.
* Reloading requires manually ejecting casings and loading bullets one by one. 

## The Mechanics of Juggling

The core gameplay loop starts by using your heavy revolver like a hammer to physically smack the dice into the air. From there, a timer starts, and it becomes a juggling act. 

To make shooting a tiny, chaotic physics object fun rather than frustrating, I engineered a dual-collision system for the bullets. The inner collision sphere handles direct impact effects, while a much larger outer collision sphere applies "wiff" velocity. This means near-misses will still catch the dice in their wake, propelling it further into the air. 

To maximize the score (Calculated by: *Time in Air* x *Shots Hit* x *Final Landed Number*), players can toss up "Ricochet Mirrors." Shooting these mirrors automatically bounces the bullet toward the dice, exponentially increasing the score multiplier upon a successful hit. 

## Technical Foundations: The Birth of ProcTex

Beyond the physics and gameplay, this jam was a massive learning experience for Tech Art. We wanted a very specific gritty, rusty aesthetic—a crunchy, color-banded, noisy image. During the jam, I experimented with a complex procedural material to achieve this look in real-time. 

While the visual results were incredible, the shader instructions were in the several hundreds, which absolutely tanked performance when applied universally. To solve this, I built a system to bake that procedural math down into flat texture maps. That exact optimization hurdle during this 1-week jam laid the direct foundation for the "ProcTex" texture pipeline plugin I would later build for *SOL CONSTRUCT*!