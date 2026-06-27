---
title: "FLECS"
date: 2024-11-29
summary: "Integrating FLECS, a lightweight C/C++ ECS, into Unreal Engine 5 to replace the suffocating boilerplate of Mass Entity while maintaining 100,000+ projectile performance."
tags:
  - Backend
  - C++
  - Optimization
  - Unreal Engine
  - ECS
authors:
  - me
featured: true
draft: false
toc: true
---

<style>
  /* Shrink image captions specifically for this blog post */
  figcaption {
    font-size: 0.85rem !important;
    line-height: 1.4 !important;
    opacity: 0.8;
    text-align: center;
  }
  
  figcaption p {
    font-size: inherit !important;
    margin-bottom: 0 !important;
  }

  /* ========================================== */
  /* 1. MAIN GLASS CENTRE PIECE                 */
  /* ========================================== */
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
  /* 2. FLOATING TOC GLASS BOX                  */
  /* ========================================== */
  .docs-toc,
  aside nav,
  .js-toc {
    background-color: rgba(30, 41, 59, 0.6) !important;
    backdrop-filter: blur(12px);
    -webkit-backdrop-filter: blur(12px);
    border: 1px solid rgba(255, 255, 255, 0.1);
    border-radius: 1rem;
    padding: 1.5rem;
    margin-top: 3rem;
  }
</style>

<script>
  document.addEventListener('DOMContentLoaded', () => {
    // 1. Table of Contents Scroll Highlighting
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

In the previous post, I proved Data-Oriented Design could simulate 100,000+ projectiles without melting the CPU. But Unreal’s Mass Entity framework came with suffocating boilerplate. I needed that same DOD performance, but with an API that didn't fight me or other teammates if they ever felt the need to expose more functionality.

I ripped Mass out entirely and integrated FLECS, a lightweight C/C++ ECS. I replaced dozens of Unreal asset files with about 150 lines of clean code. FLECS is widely used across the industry as a method to implement ECS without building it from scratch. For our case, the actual flow of interacting with Mass was just intuitive. Individual Data assets had to be made for each projectile, Data was stored in fragments which function as Structs making data retrieval and sending super messy, and on top of that Mass is so fragile that hit events were communicated using Interface events that couldn’t simple inherit from parents, but had to be implemented for every single actor in the game. But shoving a third party C++ library into Unreal Engine 5 led me to a few bugs, like Niagara only accepting 32 bit Particle IDs, with FLECS using 64 bit. The same In-Frame latency also came up, which was thankfully fixed in a very similar way so didn’t require too much trial and error and then on top of that I had a funky Garbage Collector crash that had to essentially validate whether a FLECS value still existed or not before purging,

The spawn code alone went from this:

<div style="margin-bottom: 2.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5); background-color: rgba(15, 23, 42, 0.4);">
  <img src="Old.png" class="zoomable" alt="EQS breakdown" style="width: 100%; height: auto; display: block; margin: 0 !important;" />
  <div style="padding: 0.75rem 1rem; text-align: center; font-size: 0.85rem; color: #94a3b8; font-style: italic;">
    *Query used by medium range enemies.*
  </div>
</div>

To this!

<div style="margin-bottom: 2.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5); background-color: rgba(15, 23, 42, 0.4);">
  <img src="new.png" class="zoomable" alt="EQS breakdown" style="width: 100%; height: auto; display: block; margin: 0 !important;" />
  <div style="padding: 0.75rem 1rem; text-align: center; font-size: 0.85rem; color: #94a3b8; font-style: italic;">
    *Query used by medium range enemies.*
  </div>
</div>

The actual code that needed to be written is a single Subsystem!!!!! It’s made our lives so much easier and allowed us to send more “traditional” projectile data. Objects like Damage Causers and Instigators and even Damage Types were easily send across using Weak Pointers so the Multi-threading remained stable, and time Niagara had no issues assigning Particle ID’s! This Projectile Saga is easily the most complex system I’ve ever worked with, and I still feel like the rest of the industry is using something that’s even beyond this. But for now, FLECS will be more than enough to serve our needs!