---
title: "Creating the LFTR"
date: 2024-11-29
summary: "Time for a new look!"
tags:
  - 3D Art
  - Unreal Engine
  - Blender
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

  
  /* ========================================== */
  /* GLASS IMAGE CAROUSEL CSS                   */
  /* ========================================== */
  .glass-carousel {
    display: flex;
    gap: 1rem;
    overflow-x: auto;
    padding-bottom: 1rem;
    margin-top: 2rem;
    margin-bottom: 2rem;
    scroll-snap-type: x mandatory;
    scrollbar-width: thin;
    scrollbar-color: #e05e5e rgba(255, 255, 255, 0.05);
  }

  .glass-carousel::-webkit-scrollbar {
    height: 8px;
  }
  .glass-carousel::-webkit-scrollbar-track {
    background: rgba(255, 255, 255, 0.05);
    border-radius: 4px;
  }
  .glass-carousel::-webkit-scrollbar-thumb {
    background: #e05e5e;
    border-radius: 4px;
  }

  .glass-carousel img {
    height: 300px; 
    width: auto;
    border-radius: 0.8rem;
    border: 1px solid rgba(255, 255, 255, 0.1);
    box-shadow: 0 4px 15px rgba(0,0,0,0.3);
    scroll-snap-align: start;
    flex-shrink: 0;
    object-fit: cover;
    background-color: rgba(0, 0, 0, 0.5); 
    cursor: pointer;
    transition: transform 0.2s ease, border-color 0.2s ease;
  }

  .glass-carousel img:hover {
    transform: scale(1.02);
    border-color: #e05e5e;
  }

  /* ========================================== */
  /* EXPANDED IMAGE MODAL (LIGHTBOX) CSS        */
  /* ========================================== */
  #lightbox-modal {
    position: fixed;
    z-index: 9999;
    left: 0;
    top: 0;
    width: 100%;
    height: 100%;
    background-color: rgba(15, 23, 42, 0.95);
    backdrop-filter: blur(10px);
    -webkit-backdrop-filter: blur(10px);
    display: flex;
    justify-content: center;
    align-items: center;
    opacity: 0;
    pointer-events: none;
    transition: opacity 0.3s ease;
  }

  #lightbox-modal.lightbox-visible {
    opacity: 1;
    pointer-events: auto;
  }

  .lightbox-content {
    max-width: 90%;
    max-height: 90%;
    border-radius: 1rem;
    box-shadow: 0 25px 50px -12px rgba(0, 0, 0, 0.7);
    border: 1px solid rgba(255, 255, 255, 0.1);
  }

  .lightbox-close {
    position: absolute;
    top: 30px;
    right: 40px;
    color: white;
    font-size: 40px;
    font-weight: bold;
    cursor: pointer;
    transition: color 0.2s ease;
  }

  .lightbox-close:hover {
    color: #e05e5e;
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

During development in the first few months, player movement was often quite an undecided aspect of a game that heavily relies upon it. We ended up slowly moving away from features like Gyro Aim (Which made a lot of people spin out in previous playtests) and a movement style that was frankly as intuitive as Marmite - some people got it but many didn’t. We knew these systems were holding us back, not necessarily because that style doesn’t work, but because we were trying to cram standard flight game conventions into a game that didn’t need them. 

So that led to stripping back some elements and moving in a direction that gave player’s more control. Our movement essentially turned into a version Minecraft’s creative mode, allowing the player to still move in any direction, but without Roll and the capability to go upside down. In a way it was a little sad to depart from the 6DOF movement, but we noticed immediately players were able to pick it up easier. 

Now that we were hard set on this style of movement, the visuals needed to match it. Zach and I had a proper sit down for a solid 2 weeks, really asking the important questions on  the kind of world we wanted to create. We were always so frenzied trying to get an updated build ready for the next convention, we actually never had the opportunity to sit down and plan things out properly. This was super liberating - There’s something so relieving about giving yourself a set of rules that can’t be broken.

The game was still about flight, but jets didn’t fit the vibe anymore. In fact, jets just stuck as long as they did because of the same reason we never got to properly plan things; Time. Instead, we opted to experiment with several different designs. We knew we needed modularity and a very clear silhouette.

## 3D "Sketches"

<div class="glass-carousel">
  <img src="Screenshot 2025-12-30 174025.png" alt="ProcTex Screenshot 1">
  <img src="Screenshot 2025-12-30 174032.png" alt="ProcTex Screenshot 2">
  <img src="Screenshot 2025-12-30 174044.png" alt="ProcTex Screenshot 3">
</div>

Some very primitive 3d sketches, trying to break up the different parts (Still trying to save the set style)

<div class="glass-carousel">
  <img src="Screenshot 2026-05-11 095349.png" alt="ProcTex Screenshot 1">
  <img src="Screenshot 2026-05-11 095357.png" alt="ProcTex Screenshot 2">
</div>

Trying to break away from the Jet stuff, more into some strange VTOL machine

<div class="glass-carousel">
  <img src="Screenshot 2026-05-11 095551.png" alt="ProcTex Screenshot 1">
  <img src="Screenshot 2026-05-11 095555.png" alt="ProcTex Screenshot 2">
  <img src="Screenshot 2026-05-11 095601.png" alt="ProcTex Screenshot 2">
</div>

Works more as drone design, but still far too Sci-fi and not cool enough

---
## Taking a step back

<div style="margin-bottom: 2.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5); background-color: rgba(15, 23, 42, 0.4);">
  <img src="Screenshot 2026-05-11 095745.png" class="zoomable" alt="LFTR Frame Concept" style="width: 100%; height: auto; display: block; margin: 0 !important;" />
  </div>
</div>

Then I took a step back. I was locking myself out of true modularity by including a central Hull that everything stemmed from for each design. That was the wrong way to go about it. What I should’ve done was create a standard frame that all components attach to, so I did! We were fairly set on the requirements;

- 2x “Wings”

- 2x Thrusters

- Nose

- Turret

- Rear Cargo

This made future designs way more consistent.

<div class="glass-carousel">
  <img src="Screenshot 2026-05-11 100252.png" alt="ProcTex Screenshot 1">
  <img src="Screenshot 2026-05-11 100259.png" alt="ProcTex Screenshot 2">
  <img src="Screenshot 2026-05-11 100304.png" alt="ProcTex Screenshot 2">
</div>

Breakthrough! I landed on a design that we both liked. It embodied that chunky, scrappy nature - a machine welded together at the last second.

<div class="glass-carousel">
  <img src="Screenshot 2026-05-11 100448.png" alt="ProcTex Screenshot 1">
  <img src="Screenshot 2026-05-11 100459.png" alt="ProcTex Screenshot 2">
  <img src="Screenshot 2026-05-11 100508.png" alt="ProcTex Screenshot 2">
</div>


Put together another design as a “Heavy” build to see how scalable our core Frame was.

I’ll go over the texture pipeline in a separate post, but just a few short months later we landed on this!

<div style="margin-bottom: 0.5rem; border-radius: 1rem; overflow: hidden; border: 1px solid rgba(255, 255, 255, 0.1); box-shadow: 0 10px 30px rgba(0,0,0,0.5);">
  <img src="Module Spin Sped Up.gif" class="zoomable" alt="Module Randomiser Render" style="width: 100%; height: auto; display: block; margin: 0 !important;" />
</div>