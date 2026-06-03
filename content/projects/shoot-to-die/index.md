---
title: Shoot to Die
date: 2025-11-10
summary: An incremental Dice Shooting Game
tags:
  - Unreal Engine
  - Blueprints
  - Tech Art
status: published
draft: false
image:
  preview_only: true
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

## Gameplay Trailer

<div style="border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  {{< youtube RBfGwsypPt4 >}}
</div>

## Full Demo Gameplay
<div style="height: 600px; background: rgba(255,255,255,0.05); border-radius: 1rem; padding: 2rem;">Pretend this is a huge block of text describing the demo!</div>

## Overview
<div style="height: 600px; background: rgba(255,255,255,0.05); border-radius: 1rem; padding: 2rem;">Shoot to Die is a fast-paced incremental game...</div>

## Combat Design
<div style="height: 600px; background: rgba(255,255,255,0.05); border-radius: 1rem; padding: 2rem;">We focused heavily on dice mechanics...</div>