using System;
using Microsoft.AspNetCore.Mvc;
using Blog.Domain;

namespace Blog.Controllers
{
    public class NewsController : Controller
    {
        private readonly DataManager dataManager;

        public NewsController(DataManager dataManager)
        {
            this.dataManager = dataManager;
        }

        public IActionResult Index(Guid id)
        {
            if (id != default)
            {
                return View("Show", dataManager.ServiceItems.GetServiceItemById(id));
            }

            ViewBag.TextField = dataManager.TextFields.GetTextFieldByCodeWord("PageServices");
            return View(dataManager.ServiceItems.GetServiceItems());
        }
    }
}