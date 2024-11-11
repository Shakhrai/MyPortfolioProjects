using Blog.Domain.Entities;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Identity.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Blog.Domain
{
    public class AppDbContext : IdentityDbContext<IdentityUser>
    {
        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options) { }
        public DbSet<TextField> TextFields { get; set; }
        public DbSet<ServiceItem> ServiceItems { get; set; }
        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);

            modelBuilder.Entity<IdentityRole>().HasData(new IdentityRole
            {
                Id = "4c6b2ef2-afff-4e79-a553-def423a45927",
                Name = "admin",
                NormalizedName = "ADMIN"
            });
            modelBuilder.Entity<IdentityUser>().HasData(new IdentityUser
            {
                Id = "2661c2c9-b5f8-4381-a8fd-3c537706161d",
                UserName = "admin",
                NormalizedUserName = "ADMIN",
                Email = "my@gmail.com",
                NormalizedEmail = "MY@GMAIL.COM",
                EmailConfirmed = true,
                PasswordHash = new PasswordHasher<IdentityUser>().HashPassword(null,"superpassword"),
                SecurityStamp = string.Empty
            });
            modelBuilder.Entity<IdentityUserRole<string>>().HasData(new IdentityUserRole<string>
            {
                RoleId = "4c6b2ef2-afff-4e79-a553-def423a45927",
                UserId = "2661c2c9-b5f8-4381-a8fd-3c537706161d"
            });
            modelBuilder.Entity<TextField>().HasData(new TextField
            {
                Id = new Guid("420e038b-0b2d-4494-a9b0-7ade592f9d23"),
                CodeWord = "PageIndex",
                Title = "Main"
            });
            modelBuilder.Entity<TextField>().HasData(new TextField
            {
                Id = new Guid("0b05dc38-d944-41c2-8dac-b2aef415b216"),
                CodeWord = "PageServices",
                Title = "News"
            });
            modelBuilder.Entity<TextField>().HasData(new TextField
            {
                Id = new Guid("f6af93cc-df95-4c1e-a89a-d1398a4fbe4d"),
                CodeWord = "PageContacts",
                Title = "Контакты"
            });
        }
    }
}
