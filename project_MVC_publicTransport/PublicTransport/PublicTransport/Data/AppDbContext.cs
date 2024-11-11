using Microsoft.EntityFrameworkCore;
using Microsoft.AspNetCore.Identity.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PublicTransport.Models;
using PublicTransport.Data.Entities;
using Microsoft.AspNetCore.Identity;
using System.Runtime.InteropServices;

namespace PublicTransport.Data
{
    public class AppDbContext : IdentityDbContext<IdentityUser>
    {
        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options)
        {

        }

        public DbSet<Transport> Transports { get; set; }
        public DbSet<Route> Routes{ get; set; }
        public DbSet<TextField> TextFields { get; set; }
        public DbSet<ServiceItem> ServiceItems { get; set; }
        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);


            modelBuilder.Entity<IdentityRole>().HasData(new IdentityRole
            {
                Id = "b98c7c89-c5bd-47f0-aaa5-38e8f406a6c4",
                Name = "admin",
                NormalizedName = "ADMIN"
            });
            modelBuilder.Entity<IdentityUser>().HasData(new IdentityUser
            {
                Id = "653c8567-bec1-4846-8ac9-6e07346e0f9f",
                UserName = "admin",
                NormalizedUserName = "ADMIN",
                Email = "my@gmail.com",
                NormalizedEmail = "MY@GMAIL.COM",
                EmailConfirmed = true,
                PasswordHash = new PasswordHasher<IdentityUser>().HashPassword(null, "password"),
                SecurityStamp = string.Empty
            });
            modelBuilder.Entity<IdentityUserRole<string>>().HasData(new IdentityUserRole<string>
            {
                RoleId = "b98c7c89-c5bd-47f0-aaa5-38e8f406a6c4",
                UserId = "653c8567-bec1-4846-8ac9-6e07346e0f9f"
            });
            modelBuilder.Entity<TextField>().HasData(new TextField
            {
                Id = new Guid("5932bbb3-c2d8-458c-8f91-c20d821aafc8"),
                CodeWord = "PageIndex",
                Title = "Main"
            });
            modelBuilder.Entity<TextField>().HasData(new TextField
            {
                Id = new Guid("1bd001cd-c0d0-4ae1-9bd5-9b721ab5ba03"),
                CodeWord = "PageServices",
                Title = "News"
            });
            modelBuilder.Entity<TextField>().HasData(new TextField
            {
                Id = new Guid("8efc00f2-4cb6-475b-becb-38ee373e3723"),
                CodeWord = "PageTransports",
                Title = "Transport"
            });
            modelBuilder.Entity<TextField>().HasData(new TextField
            {
                Id = new Guid("1e387612-34fa-4120-8b5a-76f5862df702"),
                CodeWord = "PageRoutes",
                Title = "Routes"
            });
            modelBuilder.Entity<TextField>().HasData(new TextField
            {
                Id = new Guid("94931302-f2ba-4881-8811-a5572701a0fb"),
                CodeWord = "PageContacts",
                Title = "Contact"
            });

        }
    }
}
